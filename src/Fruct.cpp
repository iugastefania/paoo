#include <iostream>
#include <Fruct.hpp>

    Fruct::Fruct(int g, double p):
        greutate(g),
        pret(p)
   {
       std::cout<<"Fruct constructor\n";                        
   }  

    Fruct::Fruct(const Fruct &f):
        greutate(f.greutate),
        pret(f.pret)
   {
       std::cout<<"Fruct copy-constructor\n";

   }

                                                    //Item 10 
                                                    //Item 11 
                                                    //Item 12
   Fruct&Fruct::operator=(const Fruct &f)
   {
        if(this==&f)
        {
            std::cout<<"Fruct assignment to self\n";
            return *this;
        }

        std::cout<<"Fruct assignment\n";
        this->greutate=f.greutate;
        this->pret=f.pret;
        return *this;
   }

    Fruct::~Fruct()
    {
        std::cout<<"Fruct destructor\n";
    }

    int Fruct::getgreutate() 
    {
        return greutate;
    }
