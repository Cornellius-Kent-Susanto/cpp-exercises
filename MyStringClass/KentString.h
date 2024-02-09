#ifndef Kent_String_H
#define Kent_String_H
#include <iostream>

class KentString
{
private:
    char *str;
    friend bool operator==(const KentString &lhs, const KentString &rhs);
    friend KentString operator-(const KentString &obj);
    friend KentString operator+(const KentString &lhs, const KentString &rhs);
    friend std::istream &operator>>(std::istream &is, KentString &obj);

public:
    KentString();
    ~KentString();
    KentString(const char *src);
    KentString(const KentString &src);
    KentString(KentString &&src);

    void display() const;
    int getLength() const;
    char *getString() const;

    const KentString &operator=(const KentString &rhs);
    const KentString &operator=(KentString &&rhs);
};

#endif
