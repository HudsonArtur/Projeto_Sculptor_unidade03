#include "FigGeometrica.hpp"
#include "cutBox.hpp"
#include "cutEllipsoide.hpp"
#include "cutSphere.hpp"
#include "cutVoxel.hpp"
#include "putBox.hpp"
#include "putEllipsoide.hpp"
#include "putSphere.hpp"
#include "putVoxel.hpp"
#include "sculptor.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<FigGeometrica *> figs;
  FigGeometrica *pfig;
  std::ifstream fin;
  std::string s;
  fin.open("origin.txt");

  Sculptor *sp;
  
  while (fin.good()) {
    fin >> s;
    if (fin.good()) {
      std::cout << s << "\n";
      if (s.compare("dim") == 0) {
        float nx, ny, nz;
        fin >> nx >> ny >> nz;
        sp = new Sculptor(nx, ny, nz);
      } else if (s.compare("putVoxel") == 0) {
          float x, y, z, r, g, b, a;
          fin >> x >> y >> z >> r >> g >> b >> a;
          figs.push_back(new putVoxel(x, y, z, r, g, b, a));
      } else if (s.compare("cutVoxel") == 0) {
          float x, y, z;
          fin >> x >> y >> z;
          figs.push_back(new cutVoxel(x, y, z));
      } else if (s.compare("putBox") == 0) {
          float x0, x1, y0, y1, z0, z1, r, g, b, a;
          fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
      } else if (s.compare("cutBox") == 0) {
          float x0, x1, y0, y1, z0, z1;
          fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
          figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
      } else if (s.compare("putSphere") == 0) {
          float xcenter, ycenter, zcenter, radius, r, g, b, a;
          fin >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
          figs.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
      } else if (s.compare("cutSphere") == 0) {
          float xcenter, ycenter, zcenter, radius;
          fin >> xcenter >> ycenter >> zcenter >> radius;
          figs.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
      } else if (s.compare("putEllipsoide") == 0) {
          float xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a;
          fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
        figs.push_back(new putEllipsoide(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
      } else if (s.compare("cutEllipsoide") == 0) {
          float xcenter, ycenter, zcenter, rx, ry, rz;
          fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
          figs.push_back(new cutEllipsoide(xcenter, ycenter, zcenter, rx, ry, rz));
      }
    }
  }
  
  for(int i=0; i<figs.size(); i++){
        figs[i]->draw(*sp);
  }

  sp->writeOFF("escultura.off");
  
  return 0;
}