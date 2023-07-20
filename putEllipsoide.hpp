#ifndef PUTELLIPSOIDE_HPP
#define PUTELLIPSOIDE_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class putEllipsoide : public FigGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    /*! \brief
    *Uma esfera deverá ser especificada para desenho conforme a posição do centro, seus raios em pixels, bem como sua cor e transparência.
    */
    putEllipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif