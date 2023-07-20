#ifndef CUTSPHERE_HPP
#define CUTSPHERE_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class cutSphere : public FigGeometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    /*! \brief
    *Uma esfera deverá ser especificada para remoção conforme a posição do centro e seu raio em pixels.
    */
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &s);
};


#endif