#ifndef PUTBOX_HPP
#define PUTBOX_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class putBox : public FigGeometrica{
    int x0, x1, y0, y1, z0, z1; 
public:
    /*! \brief
    *Uma caixa deverá ser especificada para desenho conforme os limites espaciais fornecidos para as três dimensões, sua cor e transparência.
    */
    putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif