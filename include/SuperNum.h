#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

#ifndef SUPERNUM_H
#define SUPERNUM_H

class SuperNum
{
    public:
        std::string num;

        SuperNum(std::string n);
        SuperNum operator * (const SuperNum&);
        SuperNum operator * (const int&);
        SuperNum operator + (const SuperNum&);
        void operator += (const SuperNum&);
        void operator = (const SuperNum&);
        bool operator == (const SuperNum&);
        void pushBack(std::string p);
        void flip();
        void print();
        virtual ~SuperNum();
    protected:
    private:
        std::string NUMLIST = "0123456789";
};

#endif // SUPERNUM_H
