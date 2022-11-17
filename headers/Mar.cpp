#ifndef MAR_HPP
#define MAR_HPP
#include <Fruct.hpp>

class Mar : public Fruct
{
    private:
        int type;
        
    public:
        Mar(int g, double p, int t);

        ~Mar();

        Mar(const Mar &m);

        Mar& operator=(const Mar &m);

};

#endif
