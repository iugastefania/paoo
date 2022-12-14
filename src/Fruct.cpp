#include <iostream>
#include <Fruct.hpp>
                                                    // Item 4 - constructor cu member initialization list
                                                    // Item 5 - copy constructor declarat
    Fruct::Fruct(int g, double p):          
        greutate(g),
        pret(p),
        rotten(false)
   {
       std::cout<<"Fruct constructor\n";                        
   }  

    Fruct::Fruct(const Fruct &f):
        greutate(f.greutate),
        pret(f.pret)
   {
       std::cout<<"Fruct copy-constructor\n";

   }

                                                    // Item 10 - assignment operators return a reference to *this
                                                    // Item 11 - handle assignment to self in operator =
                                                    // Item 12 - copy all parts of an object
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
        return this->greutate;
    }

                                                // Item 14 
    void Fruct::setIsRotten(bool r)             // functie pentru setarea rotten sau unrotten
    {
        this->rotten=r;
    }

    void Fruct::verifyRotten()                    // functie pentru verificare rotten sau unrotten
    {
        if(this->rotten)
        {
            std::cout<<"IS ROTTEN"<<std::endl;
        }
        else
            std::cout<<"IS NOT ROTTEN"<<std::endl;

    }
