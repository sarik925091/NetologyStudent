#include <iostream>
#include <fstream>
#include <vector>

class LogCommand 
{
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsolePrint : public LogCommand
{
public:
    void print(const std::string& message) override
    {
        std::cout << message << std::endl;
    }
};

class FilePrint : public LogCommand
{
    std::ofstream outFile{ "example.txt" };
public:
    void print(const std::string& message) override
    {
        if (!outFile.is_open())
        {
            std::cerr << "File opening error!" << std::endl;
            return;
        }
        else
        {
            outFile << message << " ";
        }
        outFile.close();
    }
};

class Print
{
    std::vector<LogCommand*> _com;
public:
    void add_command(LogCommand* com)
    {
        _com.push_back(com);
    }
    void print(const std::string& message, int ind)
    {
        _com[ind]->print(message);
    }
};

int main()
{
    FilePrint Fp;
    ConsolePrint Cp;
    Print print;

    print.add_command(&Fp);
    print.add_command(&Cp);

    print.print("Netology", 0);
    print.print("Netology", 1);
	return 0;

}