#include "cutSphere.hpp"
#include "sculptor.hpp"

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->radius = radius;
}

void cutSphere::draw(Sculptor &s){
  s.cutSphere(xcenter, ycenter, zcenter, radius);
}