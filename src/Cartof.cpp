#include <iostream>
#include <Cartof.hpp>
#include <Fruct.hpp>

    Cartof::Cartof(int g, double p, int t): 
        Leguma(g,p),
        type(t)
    {
        std::cout<<"Cartof constructor\n";
    }

    Cartof::~Cartof()
    {
        std::cout<<"Cartof destructor\n";
    }


