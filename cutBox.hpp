#ifndef CUTBOX_HPP
#define CUTBOX_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class cutBox : public FigGeometrica{
    int x0, x1, y0, y1, z0, z1;
public:
    /*! \brief
    *Uma caixa deverá ser especificada para remoção conforme os limites espaciais fornecidos.
    */
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void draw(Sculptor &s);
};


#endif