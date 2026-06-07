#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>

class LogMessage 
{
public:
    virtual void log(const std::string& message) {}
    virtual void set_next(LogMessage* next) {}
};


class Warning : public LogMessage
{
    LogMessage* _logMessage_next = nullptr;
    std::string _warn;
public:
    Warning(const std::string& warn) : _warn(warn) {}
    void log(const std::string& message) override
    {
        if (message == _warn)
        {
            std::cout << message << std::endl;
        }
        else if (_logMessage_next != nullptr)
        {
            _logMessage_next->log(message);
        }
        else
        {
            std::cout << "the next handler is missing!" << std::endl;
        }
    }
    void set_next(LogMessage* next) override
    {
        _logMessage_next = next;
    }
};

class Error : public LogMessage
{
    LogMessage* _logMessage_next = nullptr;
    std::string _err;
    std::ofstream outFile{ "error.txt" };
public:
    Error(const std::string& err) : _err(err) {}
    void log(const std::string& message) override
    {
        if (message == _err)
        {
            if (!outFile.is_open())
            {
                std::cerr << "File opening error!" << std::endl;
                return;
            }
            else
            {
                outFile << message << '\n';
            }
            outFile.close();
        }
        else if (_logMessage_next != nullptr)
        {
            _logMessage_next->log(message);
        }
        else
        {
            std::cout << "the next handler is missing!" << std::endl;
        }
    }
    void set_next(LogMessage* next) override
    {
        _logMessage_next = next;
    }
};

class FatalError : public LogMessage
{
    LogMessage* _logMessage_next = nullptr;
    std::string _fatalErr;
public:
    FatalError(const std::string& fatalErr) : _fatalErr(fatalErr) {}
    void log(const std::string& message) override
    {
        if (message == _fatalErr)
        {
            throw std::runtime_error(message);
        }
        else if (_logMessage_next != nullptr)
        {
            _logMessage_next->log(message);
        }
        else
        {
            std::cout << "the next handler is missing!" << std::endl;
        }
    }
    void set_next(LogMessage* next) override
    {
        _logMessage_next = next;
    }
};

class Unknown : public LogMessage
{
    LogMessage* _logMessage_next = nullptr;
    std::string _unknown;
public:
    Unknown(const std::string& unknown) : _unknown(unknown) {}
    void log(const std::string& message) override
    {
        if (message == _unknown)
        {
            throw std::runtime_error("undefined error!");
        }
        else if (_logMessage_next != nullptr)
        {
            _logMessage_next->log(message);
        }
        else
        {
            std::cout << "the next handler is missing!" << std::endl;
        }
    }
    void set_next(LogMessage* next) override
    {
        _logMessage_next = next;
    }
};

int main()
{
    try
    {
        Warning W{ "Warning" };
        Error E{ "Error" };
        FatalError FE{ "FatalError" };
        Unknown U{ "Unknow" };
        W.set_next(&E);
        E.set_next(&FE);
        FE.set_next(&U);

        W.log("Warning");
        W.log("Error");
        W.log("FatalError");
        //W.log("Unknow");    2 exception !!!
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}