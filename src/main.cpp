#include <iostream>
#include <memory>

#include <Fruct.hpp>
#include <Mar.hpp>
#include <Leguma.hpp>
#include <Cartof.hpp>


class defaultConstructorClass
{
};
                                            // Item 14
                                            // functie pentru actiunea de lock
void lock(Fruct *f)
{
    std::cout<<"Fruit is rotten"<<std::endl;
    f->setIsRotten(true);
}

                                            // functie pentru actiunea de unlock
void unlock(Fruct *f)
{
    std::cout<<"Fruit is not rotten"<<std::endl;
    f->setIsRotten(false);
}

                                            // new class for managing locks
class RottenFruct 
{
    private:
        std::shared_ptr<Fruct> Fructptr;

    public:
        explicit RottenFruct(Fruct *F):
            Fructptr(F, unlock)             // setam unlock ca si deleter
        {
            lock(Fructptr.get());
        }
};

using namespace std;

                                            // function for creating a fruit instance
Fruct* createFructInstance(int g, int p)
{
    return (new Fruct(g,p));
}


int main(){

    defaultConstructorClass d1;     // call default constructor from class
    defaultConstructorClass d2=d1;  // copy-constructor from empty class
    d2=d1;                          // copy assignment from empty class


                                    // manual initialization of an int
    int g=100;

    {
        Fruct f3(10,3);
        Mar m3(10,2,3);
    }

    std::cout<<"\n";

    Fruct f1(g,2.5);                // Fruct constructor
    Mar m1(g,1.76,2);               // Fruct constructor, Mar constructor
    Fruct f2(f1);                   // Fruct copy-constructor
    Mar m2(m1);                     // Fruct copy-constructor, Mar copy-constructor
    m1=m2;                          // Fruct assignment, Mar assignment
    f2=f1;                          // Fruct assignment
    f2=m2;                          // Fruct assignment

    std::cout<<"\n";

    Cartof c1(1,2,3);
    Leguma l1(1,2);

                                    // copy constructor and assignment are not alloged (in superclass Leguma this methods are private)
    // Cartof c2(c1);
    // c2=c1;
    // Leguma l2(l1);
    // l2=l1;

    std::cout<<"\n";

                                    // Tema 2
                                    // Item 10 - assignment operators return a reference to *this
    Fruct Fruct1(2,3);
    Fruct Fruct2(1,1);
    Fruct Fruct3(5,4);
    Fruct1=Fruct2=Fruct3;
    std::cout<<"\nGreutatea fructului: "<<Fruct1.getgreutate()<<"\n";
    std::cout<<"\n";

                                    // Item 11: Handle assignment to self in operator=
                                    // - verificare cu if in assignment op. Fruct, Mar
    f1=f1;
    m2=m2;
    std::cout<<"\n";

                                    // Item 12 - Copy all parts of an object
                                    // - daca stergem schimbarea this->type=m.type din assignment pentru Mar, Mar2 nu va avea tipul schimbat, deci nu vom copia toate partile
    Mar Mar1(1,2,4);
    Mar Mar2(7,9,3);
    Mar2=Mar1;
    std::cout<<"\nTipul marului: "<<Mar2.getType()<<"\n";
    std::cout<<"\n";


                                    // Tema 3
                                    // Item 13 - Use objects to manage resources
                                    // Auto_ptr 
    auto_ptr<Fruct> FructAuto1(createFructInstance(1,2));
    std::cout<<"\nAuto_ptr_1. Greutatea este: "<<FructAuto1->getgreutate();
    auto_ptr<Fruct> FructAuto2(FructAuto1);
    std::cout<<"\nAuto_ptr_2. Greutatea este: "<<FructAuto2->getgreutate();
    std::cout<<"\n";
                                    // FructAuto1=null dupa copiere
                                    // FructAuto2 pointeaza acum spre obiect, iar FructAuto1 este null acum, astfel nu se va mai ajunge in Incercare 2
    // std::cout<<"\nIncercare 1";
    // std::cout<<"\nAuto_ptr_1. Greutatea este: "<<FructAuto1->getgreutate();
    // std::cout<<"\nIncercare 2";
    // std::cout<<"\n";

    FructAuto1 = FructAuto2;               //FructAuto1 va pointa din nou catre obiectul creat, si FructAuto2 va fi null
    std::cout<<"\nAuto_ptr_1. Greutatea este: "<<FructAuto1->getgreutate();
    std::cout<<"\n";
    // std::cout<<"\nAuto_ptr_2. Greutatea este: "<<FructAuto2->getgreutate();
    std::cout<<"\n";


                                    // Shared_ptr
    shared_ptr<Fruct> FructShared1(createFructInstance(3,4));
    std::cout<<"\nShared_ptr_1. Greutatea este: "<<FructShared1->getgreutate();
    shared_ptr<Fruct> FructShared2(FructShared1);
    shared_ptr<Fruct> FructShared3(FructShared2);   
                                    // toate 3 vor pointa catre obiectul nou creat, greutatea avand aceeasi valoare
    std::cout<<"\nShared_ptr_2. Greutatea este: "<<FructShared2->getgreutate();
    std::cout<<"\nShared_ptr_3. Greutatea este: "<<FructShared3->getgreutate();
                                    // use_count returneaza numarul de instante shared_ptr ce manageriaza obiectul curent
    std::cout<<"\nNumber of copies: "<<FructShared1.use_count();
    std::cout<<"\n";



                                    // Item 14 - Think carefully about copying behavior in resource-managing classes
    std::cout<<"\n";
    Fruct rottenFruct(2,7);
    rottenFruct.verifyRotten();     // initial, fructul nu este rotten

    std::cout<<"\n";
    RottenFruct r1(&rottenFruct);   // fructul devine rotten
    rottenFruct.verifyRotten();    

    std::cout<<"\n";
    RottenFruct r2(r1);             
    rottenFruct.verifyRotten();     // este rotten in continuare
    std::cout<<"\n";

                                    // apoi nu va mai fi rotten
                                    // finally destructors for all objects created
    return 0;
}
