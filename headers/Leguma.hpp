#ifndef LEGUMA_HPP
#define LEGUMA_HPP

class Leguma
{
    private:
        int greutate;
        double pret;

    public:
        Leguma(int g, double p); 

        Leguma();

        virtual ~Leguma();
        
    private:
        Leguma(const Leguma &l);                 //uncopyable

        Leguma& operator=(const Leguma &l);      //copy assignment not allowed
};

#endif 
