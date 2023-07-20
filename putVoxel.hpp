#ifndef PUTVOXEL_HPP
#define PUTVOXEL_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class putVoxel : public FigGeometrica{
    int x, y, z;
public:
    /*! \brief
    *Atribui um voxel a uma determinada posição no espaço, com uma determinada cor e uma determinada transparência.
    */
    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    void draw(Sculptor &s);
};


#endif