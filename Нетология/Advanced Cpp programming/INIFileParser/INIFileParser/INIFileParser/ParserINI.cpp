#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include<Windows.h>

class IniParseError : public std::runtime_error 
{
public:
    int line_number;
    IniParseError(const std::string& msg, int line = 0)
        : std::runtime_error(msg), line_number(line) {}
};

class IniKeyNotFound : public std::runtime_error 
{
public:
    IniKeyNotFound(const std::string& msg) : std::runtime_error(msg) {}
};

class IniParser 
{
public:

    explicit IniParser(const std::string& filename) 
    {
        std::ifstream file(filename);
        if (!file.is_open()) 
        {
            throw IniParseError("Не удалось открыть файл: " + filename);
        }

        std::string line;
        std::string current_section;
        int line_num = 0;

        while (std::getline(file, line)) 
        {
            ++line_num;
            trim(line);

            if (line.empty() || line[0] == ';') 
            {
                continue;
            }

            if (line.front() == '[' && line.back() == ']') 
            {
                current_section = line.substr(1, line.size() - 2);
                trim(current_section);
                if (current_section.empty()) 
                {
                    throw IniParseError("Пустое имя секции", line_num);
                }

                if (data_.find(current_section) == data_.end()) 
                {
                    data_[current_section] = Section();
                }
                continue;
            }

            size_t delim_pos = line.find('=');
            if (delim_pos == std::string::npos) 
            {
                throw IniParseError("Неверный формат строки (нет символа '=')", line_num);
            }

            std::string key = line.substr(0, delim_pos);
            std::string value = line.substr(delim_pos + 1);
            trim(key);
            trim(value);

            if (key.empty()) 
            {
                throw IniParseError("Пустое имя ключа", line_num);
            }

            std::string section = current_section.empty() ? "GLOBAL" : current_section;

            data_[section][key] = value;
        }
    }

    // Template method for getting a value.
    // The path parameter is a string of the form "section.key" (the section and key are separated by a dot).
    // If the section is not specified (just "key"), then the "GLOBAL" section is used.
    template<typename T>
    T get_value(const std::string& path) const {
        std::string section, key;
        parse_path(path, section, key);

        auto sec_it = data_.find(section);
        if (sec_it == data_.end()) 
        {
            std::string hint = "Доступные секции: ";
            for (const auto& p : data_) 
            {
                hint += p.first + " ";
            }
            throw IniKeyNotFound("Секция '" + section + "' не найдена. " + hint);
        }

        auto key_it = sec_it->second.find(key);
        if (key_it == sec_it->second.end()) 
        {
            std::string hint = "Доступные ключи в секции '" + section + "': ";
            for (const auto& p : sec_it->second) {
                hint += p.first + " ";
            }
            throw IniKeyNotFound("Ключ '" + key + "' не найден в секции '" + section + "'. " + hint);
        }

        return convert<T>(key_it->second, section, key);
    }

private:

    using Section = std::map<std::string, std::string>;
    std::map<std::string, Section> data_;

    static void trim(std::string& s) 
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
            }));
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
            }).base(), s.end());
    }

    // Parsing the "section.key" path
    static void parse_path(const std::string& path, std::string& section, std::string& key) 
    {
        size_t dot_pos = path.find('.');
        if (dot_pos == std::string::npos) 
        {
            section = "GLOBAL";
            key = path;
        }
        else 
        {
            section = path.substr(0, dot_pos);
            key = path.substr(dot_pos + 1);
        }

        trim(section);
        trim(key);
        if (section.empty()) 
        {
            throw IniKeyNotFound("Имя секции не может быть пустым");
        }
        if (key.empty()) 
        {
            throw IniKeyNotFound("Имя ключа не может быть пустым");
        }
    }

    template<typename T>
    static T convert(const std::string& value, const std::string& section, const std::string& key) 
    {
        throw std::logic_error("Неподдерживаемый тип");
    }
};

// std::string
template<>
inline std::string IniParser::convert<std::string>(const std::string& value,
    const std::string& /*section*/,
    const std::string& /*key*/) 
{
    return value;
}

// int
template<>
inline int IniParser::convert<int>(const std::string& value,
    const std::string& section,
    const std::string& key) 
{
    try 
    {
        size_t pos;
        int result = std::stoi(value, &pos);
        if (pos != value.size()) 
        {
            throw std::invalid_argument("Не все символы числа");
        }
        return result;
    }
    catch (const std::exception& e) 
    {
        throw IniKeyNotFound("Не удалось преобразовать значение '" + value +
            "' в int для [" + section + "]." + key);
    }
}

// double
template<>
inline double IniParser::convert<double>(const std::string& value,
    const std::string& section,
    const std::string& key) 
{
    try 
    {
        size_t pos;
        double result = std::stod(value, &pos);
        if (pos != value.size()) 
        {
            throw std::invalid_argument("Не все символы числа");
        }
        return result;
    }
    catch (const std::exception& e) 
    {
        throw IniKeyNotFound("Не удалось преобразовать значение '" + value +
            "' в double для [" + section + "]." + key);
    }
}

//  bool
template<>
inline bool IniParser::convert<bool>(const std::string& value,
    const std::string& section,
    const std::string& key) 
{
    std::string lower = value;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "true" || lower == "yes" || lower == "on" || lower == "1") return true;
    if (lower == "false" || lower == "no" || lower == "off" || lower == "0") return false;
    throw IniKeyNotFound("Не удалось преобразовать значение '" + value +
        "' в bool для [" + section + "]." + key +
        " (ожидается true/false, yes/no, on/off, 1/0)");
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try 
    {
        IniParser parser("config.ini");

        std::string theme = parser.get_value<std::string>("settings.theme");
        int volume = parser.get_value<int>("settings.volume");
        bool fullscreen = parser.get_value<bool>("settings.fullscreen");
        std::string username = parser.get_value<std::string>("user.name");
        int level = parser.get_value<int>("user.level");

        std::cout << "Theme: " << theme << "\n";
        std::cout << "Volume: " << volume << "\n";
        std::cout << "Fullscreen: " << std::boolalpha << fullscreen << "\n";
        std::cout << "User: " << username << ", level " << level << "\n";

        auto wrong = parser.get_value<int>("user.score");
    }
    catch (const IniParseError& e) 
    {
        std::cerr << "Ошибка парсинга: " << e.what();
        if (e.line_number > 0)
        {
            std::cerr << " (строка " << e.line_number << ")";
        }
        std::cerr << "\n";
    }
    catch (const IniKeyNotFound& e) 
    {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Другая ошибка: " << e.what() << "\n";
    }
}