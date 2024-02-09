#ifndef Mystring_H
#define Mystring_H
#include <cctype>
#include <cstring>
#include <iostream>

class Mystring
{
private:
    char *str;

    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(const Mystring &lhs, size_t times);
    friend Mystring &operator*=(Mystring &lhs, size_t times);
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);

public:
    Mystring();
    Mystring(const char *ptr);
    Mystring(const Mystring &src);
    Mystring(Mystring &&src);
    ~Mystring();
    const char *const getstring() const;
    Mystring operator-() const;
    const Mystring &operator=(const Mystring &rhs);
    const Mystring &operator=(Mystring &&rhs);
    Mystring &operator++();
    Mystring operator++(int);
};
#endif
