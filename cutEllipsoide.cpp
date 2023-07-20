#include "cutEllipsoide.hpp"
#include "sculptor.hpp"

cutEllipsoide::cutEllipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->rx = rx;
  this->ry = ry;
  this->rz = rz;
}
void cutEllipsoide::draw(Sculptor &s){
  s.cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
}