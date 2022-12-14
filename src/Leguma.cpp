#include <iostream>
#include <Leguma.hpp>
                                                // Item 4 - constructor cu member initialization list
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

