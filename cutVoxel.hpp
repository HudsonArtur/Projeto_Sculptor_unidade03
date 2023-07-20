#ifndef CUTVOXEL_HPP
#define CUTVOXEL_HPP

#include "FigGeometrica.hpp"
#include "sculptor.hpp"

class cutVoxel : public FigGeometrica{
    int x, y, z;
public:
    /* \brief
    *Um voxel deverá ser especificado para remoção conforme sua posição no espaco.
    */
    cutVoxel(int x, int y, int z);
    void draw(Sculptor &s);
};


#endif