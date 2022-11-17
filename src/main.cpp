#include <iostream>
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

    Fruct f1(g,2.5);                //Fruct constructor
    Mar m1(g,1.76,2);               //Fruct constructor, Mar constructor
    Fruct f2(f1);                   //Fruct copy-constructor
    Mar m2(m1);                     //Fruct copy-constructor, Mar copy-constructor
    m1=m2;                          //Fruct assignment, Mar assignment
    f2=f1;                          //Fruct assignment
    f2=m2;                          //Fruct assignment

    Cartof c1(1,2,3);
    Leguma l1(1,2);

                                    // copy constructor and assignment are not alloged (in superclass Leguma this methods are private)
    // Cartof c2(c1);
    // c2=c1;
    // Leguma l2(l1);
    // l2=l1;
  

                                    //finally destructors for all objects created
    return 0;
}
