#include "poly.hpp"
#include <iostream>
#include <sstream>

int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

Poly &Poly::operator += (const Poly &b){
    int i;
    for (auto count = b.begin(); count !=b.end() ; count++)
    {
        i = count->first;
        values_[i] += count->second;
    }
    return *this;
}

Poly& Poly::operator -= (const Poly &b){
    int i;
    for (auto count = b.begin(); count != b.end(); count++)
    {
        i = count->first;
        values_[i] -= count->second;
    }
    return *this;
}

std::istream &operator>>(std::istream &is, Poly &p){

    std::string paralist;
    int mul = 0;
    char x;
    int exp = 0;
    std::getline(is, paralist, ' ');
    if (paralist.size()==0)
        std::getline(is, paralist);

    std::stringstream iss(paralist);
    while(iss >> mul >> x >> exp)
    {
        if(mul!=0)
            p[exp] += mul;

    }

    return is;
}
std::ostream &operator<<(std::ostream &os, const Poly &p){
    Poly new_p = p;
    std::string paralist;
    for (auto i = new_p.rbegin(); i != new_p.rend(); i++)
    {
        if (i->second != 0)
        {
            if (i != new_p.rbegin())
                if (i->second > 0)
                    os << "+";
        os << i->second << 'x' << i->first;
    }

        }
    return os;
}

Poly operator+(const Poly &a, const Poly &b){
    Poly c = a;
    c += b;

    return c;
}
Poly operator-(const Poly &a, const Poly &b){
    Poly c = a;
    c -= b;

    return c;
}
Poly operator-(const Poly &p){
    Poly c;
    int count = 0;
    for (auto i = p.begin(); i != p.cend(); i++)
    {
        c[count] = -p[count];
        count++;
    }

    return c;
}

bool operator==(const Poly &a, const Poly &b){
    bool flag = false;
    if (a.begin() == a.end() && b.begin() == b.end())
        flag = true;

    else if (a.begin() == a.end() || b.begin() == b.end())
        flag = false;

    else
    {
        auto ia = a.end();
        auto ib = b.end();
        ia--;
        ib--;
        if (ia->first == ib->first)
            flag = true;
    }

    return flag;
}
bool operator!=(const Poly &a, const Poly &b){
    bool flag = false;
    if (a.begin() == a.end() && b.begin() == b.end())
        flag = false;

    else if (a.begin() == a.end() || b.begin() == b.end())
        flag = true;

    else
    {
        auto ia = a.end();
        auto ib = b.end();
        ia--;
        ib--;
        if (ia->first != ib->first)
            flag = true;
    }

    return flag;
}
bool operator<(const Poly &a, const Poly &b){
    bool flag = false;
    if (a.begin() == a.end())
        flag = true;

    else if (b.begin() == b.end())
        flag = false;

    else
    {
        auto ia = a.end();
        auto ib = b.end();
        ia--;
        ib--;
        if (ia->first < ib->first)
            flag = true;

  
    }

    return flag;
}
bool operator>(const Poly &a, const Poly &b){
    bool flag = false;
    if (a.begin() == a.end())
        flag = false;

    else if (b.begin() == b.end())
        flag = true;

    else
    {
        auto ia = a.end();
        auto ib = b.end();
        ia--;
        ib--;
        std::cout << ia->first << std::endl;
        std::cout << ib->first << std::endl;
        if (ia->first > ib->first)
            flag = true;
    }

    return flag;
    }