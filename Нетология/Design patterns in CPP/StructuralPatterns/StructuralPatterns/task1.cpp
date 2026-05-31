#include <string>
#include <iostream>
#include <algorithm>
#include <xutility>

class Text 
{
public:
    virtual void render(const std::string& data) const 
    {
        std::cout << data;
    }
};


class DecoratedText : public Text 
{
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText 
{
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const 
    {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText 
{
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const 
    {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText
{
public:
    Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const
    {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText
{
public:
    Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const
    {
        std::string str = data;
        std::reverse(str.begin(), str.end());
        text_->render(str);
    }
};

class Link : public DecoratedText
{
public:
    Link(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const
    {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
    void render(const std::string& str1, const std::string& str2)
    {
        render(str1 + str2);
    }
};

int main() 
{
    auto text_block_1 = new ItalicText(new BoldText(new Text()));
    text_block_1->render("Hello world");
    std::cout << std::endl;
    auto text_block_2 = new Paragraph(new Text());
    text_block_2->render("Hello world");
    std::cout << std::endl;
    auto text_block_3 = new Reversed(new Text());
    text_block_3->render("Hello world");
    std::cout << std::endl;
    auto text_block_4 = new Link(new Text());
    text_block_4->render("netology.ru", "Hello world");
    return 0;
}