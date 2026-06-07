#include <fstream>
#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string print() = 0;
};


class PrintAsHTML : public Printable
{
public:

    virtual std::string printAsHTML() const = 0;
    std::string print() override
    {
        std::string res = printAsHTML();
        return res;
    }
};

class PrintAsText : public Printable
{
public:
    virtual std::string printAsText() const = 0;
    std::string print() override
    {
        std::string res = printAsText();
        return res;
    }
};

class PrintAsJSON : public Printable
{
public:
    virtual std::string printAsJSON() const = 0;
    std::string print() override
    {
        std::string res = printAsJSON();
        return res;
    }
};

enum class Format
{
    kText,
    kHTML,
    kJSON
};

class Data
{
public:

    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string get_data()
    {
        return data_;
    }

    Format get_format()
    {
        return format_;
    }

private:
    std::string data_;
    Format format_;
};

class PrintAsHTMLData : public PrintAsHTML
{
public:

    PrintAsHTMLData(Data* data) : _data(data) {}

    std::string printAsHTML() const override
    {
        if (_data->get_format() != Format::kHTML)
        {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + _data->get_data() + "<html/>";
    }
private:
    Data* _data;
};

class PrintAsTextData : public PrintAsText
{
public:

    PrintAsTextData(Data* data) : _data(data) {}

    std::string printAsText() const override
    {
        if (_data->get_format() != Format::kText)
        {
            throw std::runtime_error("Invalid format!");
        }
        return _data->get_data();
    }
private:
    Data* _data;
};

class PrintAsJSONData : public PrintAsJSON
{
public:

    PrintAsJSONData(Data* data) : _data(data) {}

    std::string printAsJSON() const override
    {
        if (_data->get_format() != Format::kJSON)
        {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + _data->get_data() + "\"}";
    }

private:
    Data* _data;
};


void saveTo(std::ofstream& file, Printable* printable)
{
    file << printable->print() << '\n';
}



int main()
{
    std::ofstream outFile{ "Log.txt" };

    Data data_html{ "--html--", Format::kHTML };
    Data data_Text{ "--text--", Format::kText };
    Data data_JSON{ "--json--", Format::kJSON};

    PrintAsHTMLData html(&data_html);
    PrintAsTextData Text(&data_Text);
    PrintAsJSONData JSON(&data_JSON);

    saveTo(outFile, &html);
    saveTo(outFile, &Text);
    saveTo(outFile, &JSON);
    return 0;
}