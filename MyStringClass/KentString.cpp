#include "KentString.h"

#include <cstring>

KentString::KentString()
    : str{new char[1]{'\0'}}
{
    std::cout << "Default Constructor" << std::endl;
}

KentString::~KentString()
{
    if (str != nullptr)
    {
        std::cout << "Default Destructor on " << str << std::endl;
    }
    else
    {
        std::cout << "Destructor on NullPtr" << std::endl;
    }
    delete[] str;
}

KentString::KentString(const char *src)
{
    if (src == nullptr)
    {
        KentString();
    }
    else
    {
        str = new char[strlen(src) + 1];
        strcpy(str, src);
        std::cout << "Constructor on " << str << std::endl;
    }
}

KentString::KentString(const KentString &src)
    : KentString{src.str}
{
    std::cout << "Deep Copy on " << str << std::endl;
}

KentString::KentString(KentString &&src)
    : str{src.str}
{
    std::cout << "Move Constructor on " << src.str << std::endl;
    src.str = nullptr;
}
void KentString::display() const { std::cout << str << " : " << getLength() << std::endl; }

int KentString::getLength() const { return strlen(str); }

char *KentString::getString() const { return str; }

const KentString &KentString::operator=(const KentString &rhs)
{
    if (this == &rhs)
    {
        return (*this);
    }

    delete[] this->str;
    this->str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return (*this);
}

const KentString &KentString::operator=(KentString &&rhs)
{
    std::cout << "Move Assignment" << std::endl;
    if (this == &rhs)
    {
        return (*this);
    }
    delete[] this->str;
    this->str = rhs.str;
    rhs.str = nullptr;
    return (*this);
}

bool operator==(const KentString &lhs, const KentString &rhs)
{
    return (strcmp(lhs.str, rhs.str) == 0);
}

KentString operator-(const KentString &obj)
{
    KentString temp{obj.str};

    for (size_t i{}; i < strlen(obj.str); i++)
    {
        temp.str[i] = tolower(obj.str[i]);
    }
    return temp;
}

KentString operator+(const KentString &lhs, const KentString &rhs)
{
    KentString temp{lhs.str};
    strcat(temp.str, rhs.str);
    return temp;
}

std::istream &operator>>(std::istream &is, KentString &obj)
{
    char *buff = new char[1000];
    is.getline(buff, 1000);
    obj = KentString{buff};
    delete[] buff;
    return is;
}
