#ifndef FRUCT_HPP
#define FRUCT_HPP

class Fruct
{
    private:
        int greutate;
        double pret;
        bool rotten;                // am adaugat un boolean pentru a verifica daca este rotten sau unrotten (Item 14)
                                    // constructor initialize everything in the object (member initialization list instead of assignments)
                                    // order is correct

    public:
        Fruct(int g, double p);   

        Fruct(const Fruct &f);

        Fruct& operator=(const Fruct &f);

        virtual ~Fruct();

        int getgreutate();

                                        // Item 14 

        void setIsRotten(bool r);       // functie pentru setare rotten sau unrotten

        void verifyRotten();            // functie pentru verificare rotten sau unrotten
};

#endif 
