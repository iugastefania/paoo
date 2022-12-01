#include <iostream>
#include <memory>
#include <mutex>

#include <Fruct.hpp>
#include <Mar.hpp>
#include <Leguma.hpp>
#include <Cartof.hpp>

class defaultConstructorClass
{
};


int main(){

    defaultConstructorClass d1;     //call default constructor from class
    defaultConstructorClass d2=d1;  //copy-constructor from empty class
    d2=d1;                          //copy assignment from empty class


                                    //manual initialization of an int
    int g=100;

    {
        Fruct f3(10,3);
        Mar m3(10,2,3);
    }

    std::cout<<"\n";

    Fruct f1(g,2.5);                //Fruct constructor
    Mar m1(g,1.76,2);               //Fruct constructor, Mar constructor
    Fruct f2(f1);                   //Fruct copy-constructor
    Mar m2(m1);                     //Fruct copy-constructor, Mar copy-constructor
    m1=m2;                          //Fruct assignment, Mar assignment
    f2=f1;                          //Fruct assignment
    f2=m2;                          //Fruct assignment

    std::cout<<"\n";

    Cartof c1(1,2,3);
    Leguma l1(1,2);

                                    // copy constructor and assignment are not alloged (in superclass Leguma this methods are private)
    // Cartof c2(c1);
    // c2=c1;
    // Leguma l2(l1);
    // l2=l1;

    std::cout<<"\n";

                                    //Tema 2
                                    //Item 10 - assignment operators return a reference to *this
    Fruct Fruct1(2,3);
    Fruct Fruct2(1,1);
    Fruct Fruct3(5,4);
    Fruct1=Fruct2=Fruct3;
    std::cout<<"\nGreutatea fructului: "<<Fruct1.getgreutate()<<"\n";
    std::cout<<"\n";

                                    //Item 11: Handle assignment to self in operator=
                                    // - verificare cu if in assignment op. Fruct, Mar
    f1=f1;
    m2=m2;
    std::cout<<"\n";

                                    //Item 12 - Copy all parts of an object
                                    // - daca stergem schimbarea this->type=m.type din assignment pentru Mar, Mar2 nu va avea tipul schimbat, deci nu vom copia toate partile
    Mar Mar1(1,2,4);
    Mar Mar2(7,9,3);
    Mar2=Mar1;
    std::cout<<"\nTipul marului: "<<Mar2.getType()<<"\n";
    std::cout<<"\n";

                                    //finally destructors for all objects created
    return 0;
}
