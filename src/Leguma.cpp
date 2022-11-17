#include <iostream>
#include <Leguma.hpp>

    Leguma::Leguma(int g, double p):
        greutate(g),
        pret(p)
    {
        std::cout<<"Leguma constructor\n";                        
    }  

    Leguma::Leguma()
    {
    }

    Leguma::~Leguma()
    {
        std::cout<<"Leguma destructor\n";
    }

