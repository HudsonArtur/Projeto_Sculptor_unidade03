#ifndef FIGGEOMETRICA_HPP
#define FIGGEOMETRICA_HPP

#include "sculptor.hpp"

class FigGeometrica{
protected:
    float r, g, b, a;
public:
    /*! \brief
    *Construtor da classe FigGeometrica
    */
    FigGeometrica();
    /*! \brief
    *Função virtual pura draw
    *instrui o objeto a se desenhar em um objeto do tipo Sculptor
    */
    virtual void draw(Sculptor &s)=0;
};

#endif