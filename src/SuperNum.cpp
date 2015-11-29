#include "SuperNum.h"

SuperNum::SuperNum(std::string n)
{
    num = "";
    for (unsigned int C = 0;C < n.length();C++)
        if (NUMLIST.find(n[C]) == std::string::npos)
            throw std::invalid_argument("Invalid input characters into number");
    num = n;
}

SuperNum SuperNum::operator * (const SuperNum& rhs)
{
    SuperNum lhs = (*this);

}

SuperNum SuperNum::operator * (const int& rhs)
{
    SuperNum lhs = (*this);
    SuperNum total {"0"};
    for (int C = 0;C < rhs;C++)
    {
        total += lhs;
    }
    return total;
}

SuperNum SuperNum::operator + (const SuperNum& rhs)
{
    SuperNum lhs = (*this);
    SuperNum output {""};
    unsigned int carry = 0, add;
    for (unsigned int C = 0;C < lhs.num.length() && C < rhs.num.length();C++)
    {
        add = (rhs.num[rhs.num.length()-C-1] - '0') + (lhs.num[lhs.num.length()-C-1] - '0') + carry;
        //std::cout << "Add: " << add << " rhs[" << C << "] = " << (rhs.num[rhs.num.length()-C-1] - '0')
        //                            << ", lhs[" << C << "] = " << (lhs.num[lhs.num.length()-C-1] - '0') << std::endl;
        std::string sadd = std::to_string(add);
        add = sadd[sadd.length() - 1] - '0';
        if (sadd.length() > 1)
            carry = std::stoi(sadd.substr(0, sadd.length()-1));
        else
            carry = 0;
        //std::cout << "Carry: " << carry << std::endl;
        output.pushBack(std::to_string(add));
    }

    std::string appending = "";
    if (lhs.num.length() > rhs.num.length())
        appending = lhs.num.substr(0, lhs.num.length() - rhs.num.length());
    else if (lhs.num.length() < rhs.num.length())
        appending = rhs.num.substr(0, rhs.num.length() - lhs.num.length());
    else if (carry != 0)
        appending = std::to_string(carry);
    output.pushBack(appending);
    std::reverse(output.num.begin(), output.num.end());
    return output;
}

void SuperNum::operator += (const SuperNum& rhs)
{
    //rhs.print();
    (*this) = (*this) + rhs;
}

void SuperNum::operator = (const SuperNum& rhs)
{
    //SuperNum lhs = (*this);
    (*this).num = rhs.num;
}

bool SuperNum::operator == (const SuperNum& rhs)
{
    SuperNum lhs = (*this);
    return (lhs.num == rhs.num);
}

void SuperNum::pushBack(std::string p)
{
    (*this).num.append(p);
}

void SuperNum::flip()
{
    std::reverse((*this).num.begin(), (*this).num.end());
}

void SuperNum::print()
{
    std::cout << "Number is " << num << std::endl;
}

SuperNum::~SuperNum()
{
}
