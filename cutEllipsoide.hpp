#ifndef CUTELLIPSOIDE_HPP
#define CUTELLIPSOIDE_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class cutEllipsoide : public FigGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    /*! \brief
    *Uma esfera deverá ser especificada para remoção conforme a posição do centro e seus raios em pixels.
    */
    cutEllipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void draw(Sculptor &s);
};

#endif