#ifndef PUTSPHERE_HPP
#define PUTSPHERE_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class putSphere : public FigGeometrica{
    int xcenter, ycenter, zcenter
, radius;
public:
    /*! \brief
    *Uma esfera deverá ser especificada para desenho conforme a posição do centro, seu raio em pixels, bem como sua cor e transparência.
    */
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif