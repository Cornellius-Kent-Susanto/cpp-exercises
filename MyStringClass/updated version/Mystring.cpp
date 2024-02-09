#include "Mystring.h"

Mystring::Mystring()
    : str{new char[1]{'\0'}}
{
    std::cout << "default constructor" << std::endl;
}

Mystring::Mystring(const char *ptr)
{
    if (ptr == nullptr)
    {
        this->str = new char[1]{'\0'};
        std::cout << "Constructor on nullptr" << std::endl;
    }
    else
    {
        this->str = new char[std::strlen(ptr) + 1];
        strcpy(this->str, ptr);
        std::cout << "Constructor on " << this->str << std::endl;
    }
}

Mystring::Mystring(Mystring &&src)
    : str{src.str}
{
    src.str = nullptr;
    std::cout << "Move constructor on " << this->str << std::endl;
}
Mystring::~Mystring()
{
    if (this->str == nullptr)
    {
        std::cout << "Destructor on nullptr" << std::endl;
    }
    else
    {
        std::cout << "Destructor on " << this->str << std::endl;
    }
    delete[] this->str;
}
const char *const Mystring::getstring() const
{
    return this->str;
}

Mystring::Mystring(const Mystring &src)
    : Mystring{src.str}
{
    std::cout << "Deep copy on : " << this->str << std::endl;
}

Mystring Mystring::operator-() const
{
    Mystring temp{this->str};
    for (size_t i{}; i < strlen(temp.str); i++)
    {
        *((temp.str) + i) = tolower(*((temp.str) + i));
    }
    return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
    return (strcmp(lhs.str, rhs.str) == 0);
}
bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
    return (!operator==(lhs, rhs));
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
    Mystring temp{lhs.str};
    strcat(temp.str, rhs.str);
    return temp;
}

bool operator<(const Mystring &lhs, const Mystring &rhs)
{
    return ((*(lhs.str)) < (*(rhs.str)));
}

bool operator>(const Mystring &lhs, const Mystring &rhs)
{
    return ((*(lhs.str)) > (*(rhs.str)));
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs)
{
    strcat(lhs.str, rhs.str);
    return lhs;
}

Mystring operator*(const Mystring &lhs, size_t times)
{
    Mystring temp{};
    if (times == 0)
    {
        return temp;
    }
    for (size_t i{0}; i < times; i++)
    {
        temp += lhs;
    }
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

const Mystring &Mystring::operator=(const Mystring &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete this->str;
    this->str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}

const Mystring &Mystring::operator=(Mystring &&rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete this->str;
    this->str = rhs.str;
    rhs.str = nullptr;
    std::cout << "Move assignment on " << this->str << std::endl;
    return *this;
}

Mystring &operator*=(Mystring &lhs, size_t times)
{
    lhs = lhs * times;
    return lhs;
}

Mystring &Mystring::operator++()
{
    for (size_t i{}; i < strlen(this->str); i++)
    {
        *(this->str + i) = toupper(*(this->str + i));
    }
    return *this;
}

Mystring Mystring::operator++(int)
{
    Mystring temp{*this};
    ++(*this);
    return temp;
}
