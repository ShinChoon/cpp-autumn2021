#include "poly.hpp"
#include <sstream>
#include <list>
#include <iostream>

int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

Poly& Poly::operator+=(const Poly& b){
    for(auto itr = b.cbegin(); itr != b.cend(); itr++){
        this->values_[itr->first] += b[itr->first];
    }
    return *this;
}

Poly& Poly::operator-=(const Poly& b){
    for(auto itr = b.cbegin(); itr != b.cend(); itr++){
        this->values_[itr->first] -= b[itr->first];
    }
    return *this;
}

std::istream& operator>>(std::istream &is, Poly &p){
    std::string line;
    is >> line ;

    std::stringstream ss;
    ss << line;

    int mul;
    char x;
    int exp;
    
    std::map<int,int> mul_exp_map;

    while (ss >> mul >> x >> exp)
    {
        if (mul_exp_map.find(exp) != mul_exp_map.end())
        {
            mul_exp_map[exp] += mul;
        }
        else
        {
            mul_exp_map.insert({exp, mul});
        }
    }

        for (auto m_iter=mul_exp_map.begin(); m_iter != mul_exp_map.end(); m_iter++)
        {
            p[m_iter->first] = m_iter->second;
        }

    return is;
}


std::ostream& operator<<(std::ostream& os, const Poly& p){
    Poly new_p = p;
    bool first_round = true;
    for(auto itr =new_p.rbegin(); itr != new_p.rend(); itr++){
        if(itr->second > 0 && first_round){
            os << itr->second << "x" << itr->first;
        }else if(itr->second > 0){
            os << "+" << itr->second << "x" << itr->first;
        }else if(itr->second < 0){
            os << itr->second << "x" << itr->first;
        }
        first_round = false;
    }
    return os;
}

Poly operator+(const Poly& a, const Poly& b){
    Poly new_p;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        new_p[itr->first] += a[itr->first];
    }
    for(auto itr = b.begin(); itr != b.end(); itr++){
        new_p[itr->first] += b[itr->first];
    }

    return new_p;
}

Poly operator-(const Poly &a, const Poly &b)
{
    Poly new_p;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        new_p[itr->first] += a[itr->first];
    }
    for(auto itr = b.begin(); itr != b.end(); itr++){
        new_p[itr->first] -= b[itr->first];
    }
    return new_p;
}

Poly operator-(const Poly& p){
    Poly new_p = p;
    for(auto itr = new_p.begin(); itr != new_p.end(); itr++){
        itr->second = -1 * itr->second;
    }
    return new_p;
}

bool operator<(const Poly& a, const Poly& b){

    int a_high = -1;
    int b_high = -1;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        a_high = itr->first;
    }
    for(auto itr = b.begin(); itr != b.end(); itr++){
        b_high = itr->first;
    }
    return a_high < b_high;
}

bool operator==(const Poly &a, const Poly &b){
    int a_high = -1;
    int b_high = -1;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        a_high = itr->first;
    }
    for(auto itr = b.begin(); itr != b.end(); itr++){
        b_high = itr->first;
    }
    return a_high == b_high;
}
bool operator>(const Poly& a, const Poly& b){
    
    int a_high = -1;
    int b_high = -1;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        a_high = itr->first;
    }
    for(auto itr = b.begin(); itr != b.end(); itr++){
        b_high = itr->first;
    }
    return a_high > b_high;
}
bool operator!=(const Poly &a, const Poly &b)
{
    int a_high = -1;
    int b_high = -1;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        a_high = itr->first;
    }
    for(auto itr = b.begin(); itr != b.end(); itr++){
        b_high = itr->first;
    }
    return a_high != b_high;
}