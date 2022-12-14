#include <iostream>
#include <Mar.hpp>
                                                    // Item 4 - constructor cu member initialization list
                                                    // Item 5 - copy constructor declarat
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

                                                    // Item 10 - assignment operators return a reference to *this
                                                    // Item 11 - handle assignment to self in operator =
                                                    // Item 12 - copy all parts of an object                                                  
    Mar& Mar::operator=(const Mar &m)
    {
        if(this==&m)
        {
            std::cout<<"Mar assignment to self\n";
            return *this;
        }

        Fruct::operator=(m);
        std::cout<<"Mar assignment\n";
        this->type=m.type;
        return *this;
    }

    int Mar::getType()
    {
       return type;
    }




