#include <iostream>
#include <Mar.hpp>

    Mar::Mar(int g, double p, int t): 
        Fruct(g,p),
        type(t)
    {
        std::cout<<"Mar constructor\n";
    }

    Mar::~Mar()
    {
        std::cout<<"Mar destructor\n";
    }

    Mar::Mar(const Mar &m):
        Fruct(m),
        type(m.type)
    {
        std::cout<<"Mar copy-constructor\n";
    }

    Mar& Mar::operator=(const Mar &m)
    {
        Fruct::operator=(m);
        std::cout<<"Mar assignment\n";
        this->type=m.type;
        return *this;
    }




