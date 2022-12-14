#include <iostream>
#include <Cartof.hpp>

    Cartof::Cartof(int g, double p, int t):         // Item 4 - constructor cu member initialization list
        Leguma(g,p),
        type(t)
    {
        std::cout<<"Cartof constructor\n";
    }

    Cartof::~Cartof()
    {
        std::cout<<"Cartof destructor\n";
    }


