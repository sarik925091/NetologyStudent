#include <iostream>
#include <pqxx/pqxx>
#include <memory>
#include <optional>
#include <vector>

struct ClientInfo 
{
    int id;
    std::string first_name;
    std::string last_name;
    std::string email;
    std::vector<std::string> phones;
};

class Database 
{
private:
    pqxx::connection& conn_;

public:
    Database(pqxx::connection& conn) : conn_(conn) {}

    void addClient(const std::string& prep_name, const std::string& first_name, const std::string& last_name, const std::string& email) 
    {
        pqxx::work tx(conn_);
        tx.exec_prepared(prep_name, first_name, last_name, email);
        tx.commit();
        std::cout << "Клиент добавлен.\n";
    }

    void addPhone(const std::string& prep_name, const std::string& phone, int client_id) 
    {
        pqxx::work tx(conn_);
        tx.exec_prepared(prep_name, phone, client_id);
        tx.commit();
        std::cout << "Телефон добавлен.\n";
    }

    void updateClientInfo(const std::string& prep_name, const std::string& new_value, int client_id) 
    {
        pqxx::work tx(conn_);
        tx.exec_prepared(prep_name, new_value, client_id);
        tx.commit();
        std::cout << "Информация клиента обновлена.\n";
    }

    void deletePhone(const std::string& prep_name, int phone_id) 
    {
        pqxx::work tx(conn_);
        tx.exec_prepared(prep_name, phone_id);
        tx.commit();
        std::cout << "Телефон удалён.\n";
    }

    void deleteClient(const std::string& prep_name, int client_id) 
    {
        pqxx::work tx(conn_);
        tx.exec_prepared(prep_name, client_id);
        tx.commit();
        std::cout << "Клиент удалён.\n";
    }

    std::vector<ClientInfo> findClients(const std::string& prep_name, const std::string& value) 
    {
        pqxx::work tx(conn_);
        pqxx::result res = tx.exec_prepared(prep_name, value);
        std::vector<ClientInfo> clients;

        for (const auto& row : res) 
        {
            ClientInfo client;
            client.id = row["id"].as<int>();
            client.first_name = row["first_name"].as<std::string>();
            client.last_name = row["last_name"].as<std::string>();
            client.email = row["email"].as<std::string>();

            pqxx::result phones = tx.exec_prepared("find_phones_by_client", client.id);
            for (const auto& ph : phones) 
            {
                client.phones.push_back(ph["phone"].as<std::string>());
            }

            clients.push_back(std::move(client));
        }

        tx.commit();
        return clients;
    }
};

class SqlTemplates 
{
public:
    static std::string addClient() 
    {
        return "INSERT INTO clients (first_name, last_name, email) VALUES ($1, $2, $3);";
    }

    static std::string addPhone() 
    {
        return "INSERT INTO phones (phone, client_id) VALUES ($1, $2);";
    }

    static std::string updateFirstName() 
    {
        return "UPDATE clients SET first_name = $1 WHERE id = $2;";
    }

    static std::string updateLastName() 
    {
        return "UPDATE clients SET last_name = $1 WHERE id = $2;";
    }

    static std::string updateEmail() 
    {
        return "UPDATE clients SET email = $1 WHERE id = $2;";
    }

    static std::string deletePhoneById() 
    {
        return "DELETE FROM phones WHERE id = $1;";
    }

    static std::string deleteClientById() 
    {
        return "DELETE FROM clients WHERE id = $1;";
    }

    static std::string findClientByFirstName() 
    {
        return "SELECT id, first_name, last_name, email FROM clients WHERE first_name = $1;";
    }

    static std::string findClientByLastName() 
    {
        return "SELECT id, first_name, last_name, email FROM clients WHERE last_name = $1;";
    }

    static std::string findClientByEmail() 
    {
        return "SELECT id, first_name, last_name, email FROM clients WHERE email = $1;";
    }

    static std::string findClientByPhone() 
    {
        return "SELECT DISTINCT c.id, c.first_name, c.last_name, c.email "
            "FROM clients c JOIN phones p ON c.id = p.client_id WHERE p.phone = $1;";
    }

    static std::string findPhonesByClient() 
    {
        return "SELECT phone FROM phones WHERE client_id = $1;";
    }
};

void createTables(pqxx::connection& conn) 
{
    pqxx::work tx(conn);
    tx.exec(R"(
        CREATE TABLE IF NOT EXISTS clients (
            id SERIAL PRIMARY KEY,
            first_name VARCHAR(100) NOT NULL,
            last_name VARCHAR(100) NOT NULL,
            email VARCHAR(255) UNIQUE NOT NULL
        );
        CREATE TABLE IF NOT EXISTS phones (
            id SERIAL PRIMARY KEY,
            phone VARCHAR(100),
            client_id INTEGER NOT NULL REFERENCES clients(id) ON DELETE CASCADE
        );
    )");
    tx.commit();
    std::cout << "Таблицы созданы (если отсутствовали).\n";
}

int main() 
{
    try 
    {
        pqxx::connection conn(
            "host=localhost "
            "port=5432 "
            "dbname=testCXX "
            "user=postgres "
            "password=925091"
        );

        createTables(conn);

        conn.prepare("add_client", SqlTemplates::addClient());
        conn.prepare("add_phone", SqlTemplates::addPhone());
        conn.prepare("update_first_name", SqlTemplates::updateFirstName());
        conn.prepare("update_last_name", SqlTemplates::updateLastName());
        conn.prepare("update_email", SqlTemplates::updateEmail());
        conn.prepare("delete_phone", SqlTemplates::deletePhoneById());
        conn.prepare("delete_client", SqlTemplates::deleteClientById());
        conn.prepare("find_by_first_name", SqlTemplates::findClientByFirstName());
        conn.prepare("find_by_last_name", SqlTemplates::findClientByLastName());
        conn.prepare("find_by_email", SqlTemplates::findClientByEmail());
        conn.prepare("find_by_phone", SqlTemplates::findClientByPhone());
        conn.prepare("find_phones_by_client", SqlTemplates::findPhonesByClient());

        Database db(conn);

        db.addClient("add_client", "Sardor", "Majidov", "mazidovsardor@gmail.com");

        std::cout << "\n=== Поиск по email ===\n";
        auto clients_by_email = db.findClients("find_by_email", "mazidovsardor@gmail.com");
        for (const auto& client : clients_by_email) 
        {
            std::cout << "ID: " << client.id << ", Имя: " << client.first_name
                << ", Фамилия: " << client.last_name << ", Email: " << client.email << "\n";
            for (const auto& phone : client.phones) 
            {
                std::cout << "  Телефон: " << phone << "\n";
            }
        }

        db.addPhone("add_phone", "999 888 7777", 1);

        std::cout << "\n=== Поиск по телефону ===\n";
        auto clients_by_phone = db.findClients("find_by_phone", "999 888 7777");
        for (const auto& client : clients_by_phone) 
        {
            std::cout << "ID: " << client.id << ", Имя: " << client.first_name
                << ", Фамилия: " << client.last_name << ", Email: " << client.email << "\n";
            for (const auto& phone : client.phones) 
            {
                std::cout << "  Телефон: " << phone << "\n";
            }
        }

        db.updateClientInfo("update_email", "sardor.new@example.com", 1);

        std::cout << "\n=== После обновления email ===\n";
        auto clients_updated = db.findClients("find_by_email", "sardor.new@example.com");
        for (const auto& client : clients_updated) 
        {
            std::cout << "ID: " << client.id << ", Имя: " << client.first_name
                << ", Фамилия: " << client.last_name << ", Email: " << client.email << "\n";
            for (const auto& phone : client.phones) 
            {
                std::cout << "  Телефон: " << phone << "\n";
            }
        }

        // db.deletePhone("delete_phone", 1);
        // db.deleteClient("delete_client", 1);

    }
    catch (const pqxx::sql_error& e) 
    {
        std::cerr << "SQL ошибка: " << e.what() << std::endl;
        std::cerr << "Запрос: " << e.query() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
