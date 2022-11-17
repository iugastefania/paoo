#ifndef CARTOF_HPP
#define CARTOF_HPP
#include <Leguma.hpp>

class Cartof : private Leguma
{
    private:
        int type;

    public:
        Cartof(int g, double p, int t);

        ~Cartof();

};

#endif
