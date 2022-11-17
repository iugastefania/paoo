#ifndef FRUCT_HPP
#define FRUCT_HPP

class Fruct
{
    private:
        int greutate;
        double pret;
                        //constructor initialize everything in the object (member initialization list instead of assignments)
                        //order is correct

    public:
        Fruct(int g, double p);   

        Fruct(const Fruct &f);

        Fruct& operator=(const Fruct &f);

        virtual ~Fruct();

        int getgreutate();
};

#endif 
