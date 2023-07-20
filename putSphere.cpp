#include "putSphere.hpp"


putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->radius = radius;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void putSphere::draw(Sculptor &s){
  s.setColor(r, g, b, a);
  s.putSphere(xcenter, ycenter, zcenter, radius);
}