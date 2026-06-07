#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Observer 
{
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};


class Observable
{
public:
    void add_observer(Observer* obs)
    {
        _observers.push_back(obs);
    }

    void removeObserver(Observer* observer) 
    {
        _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
    }

    void warning(const std::string& message) const 
    {
        for (auto obs : _observers)
            if (obs) obs->onWarning(message);
    }

    void error(const std::string& message) const 
    {
        for (auto obs : _observers)
            if (obs) obs->onError(message);
    }

    void fatalError(const std::string& message) const 
    {
        for (auto obs : _observers)
            if (obs) obs->onFatalError(message);
    }

private:
    std::vector<Observer*> _observers;

};

class Warning : public Observer
{
public:
    void onWarning(const std::string& message)
    {
        std::cout << message << std::endl;
    }
};

class Error : public Observer
{
    std::ofstream outFile{ "error.txt" };
public:
    void onError(const std::string& message)
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
};

class FatalError : public Observer
{
    std::ofstream outFile{ "fatalError.txt" };
public:
    void onFatalError(const std::string& message)
    {
        std::cout << message << std::endl;

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
};

int main()
{
    FatalError FE;
    Warning W;
    Error E;
    Observable obs;
    obs.add_observer(&FE);
    obs.add_observer(&W);
    obs.add_observer(&E);

    obs.warning("warning");
    obs.error("error");
    obs.fatalError("fatalError");

    return 0;
}

