#include "sculptor.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){

  nx = _nx;
  ny = _ny;
  nz = _nz;


  v = new Voxel**[nx];

    for (int x = 0; x < nx; x++){
        v[x] = new Voxel *[nx];
    }
    for (int x = 0; x < nx; x++){
        for(int y = 0; y<ny; y++){
            v[x][y] = new Voxel [nz];
        }
    }
  
  for(int x = 0; x < nx; x++){ // Atribuição dos valores iniciais das cores
        for (int y = 0; y < ny; y++){
            for (int z = 0; z < nz; z++){
                v[x][y][z].show = false;

                v[x][y][z].r = 0;
                v[x][y][z].g = 0;
                v[x][y][z].b = 0;
                v[x][y][z].a = 0;
            }
        }
    }

}

Sculptor::~Sculptor(){

  for (int x = 0; x < nx; x++){
        for(int y = 0; y<ny; y++){
            delete v[x][y];
        }
    }

    for (int x = 0; x < nx; x++){
        delete v[x];
    }

    delete v;
}

void Sculptor::setColor(float r, float g, float b, float alpha) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
  if((x<=nx && x>=0) && (y<=ny && y>=0) && (z<=nz && z>=0)){ 
   v[x][y][z].r = r;
   v[x][y][z].g = g;
   v[x][y][z].b = b;
   v[x][y][z].a = a;
   v[x][y][z].show = true;
 }
}

void Sculptor::cutVoxel(int x, int y, int z){
  if((x<=nx && x>=0) && (y<=ny && y>=0) && (z<=nz && z>=0)){
    v[x][y][z].show = false;
  }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int x=x0; x< x0 + x1; x++){
    for(int y=y0; y< y0 + y1; y++){
      for(int z=z0; z< z0 + z1; z++){
        Sculptor::putVoxel(x,y,z);
      } 
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int x=x0; x< x0 + x1; x++){
    for(int y=y0; y< y0 + y1; y++){
      for(int z=z0; z< z0 + z1; z++){
        Sculptor::cutVoxel(x,y,z);
      } 
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int x = xcenter - radius; x<= xcenter + radius; x++){
    for(int y = ycenter - radius; y<= ycenter + radius; y++){
      for(int z = zcenter - radius; z<= zcenter + radius; z++){
        if(pow(x-xcenter,2)+pow(y-ycenter,2)+pow(z-zcenter,2)<=pow(radius,2)){
          Sculptor::putVoxel(x,y,z);
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int x = xcenter - radius; x<= xcenter + radius; x++){
    for(int y = ycenter - radius; y<= ycenter + radius; y++){
      for(int z = zcenter - radius; z<= zcenter + radius; z++){
        if(pow(x-xcenter,2)+pow(y-ycenter,2)+pow(z-zcenter,2)<=pow(radius,2)){
          Sculptor::cutVoxel(x,y,z);
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int x = xcenter - rx; x<=xcenter + rx; x++){
    for(int y = ycenter - ry; y<=ycenter + ry; y++){
      for(int z = zcenter - rz; z<=zcenter + rz; z++){
        if(pow(x-xcenter,2)/pow(rx,2) + pow(y-ycenter,2)/pow(ry,2) + pow(z-zcenter,2)/pow(rz,2)<=1){
          Sculptor::putVoxel(x,y,z);
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int x = xcenter - rx; x<=xcenter + rx; x++){
    for(int y = ycenter - ry; y<=ycenter + ry; y++){
      for(int z = zcenter - rz; z<=zcenter + rz; z++){
        if(pow(x-xcenter,2)/pow(rx,2) + pow(y-ycenter,2)/pow(ry,2) + pow(z-zcenter,2)/pow(rz,2)<=1){
          Sculptor::cutVoxel(x,y,z);
        }
      }
    }
  }
}
void Sculptor::writeOFF(const char *filename){
  std::ofstream outFile;
	outFile.open(filename);

  if (!outFile.is_open()){
        std::cout << "Erro ao abrir arquivo: "<< filename << std::endl;
        exit(0);
    }

	int Nvoxel = 0;

	for (int i = 0; i < nx; i++) { // Conta quantos voxels tem no desenho
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].show) {
					Nvoxel++;
				}
			}
		}
	}


	outFile << "OFF" << std::endl << Nvoxel * 8 << " " << Nvoxel * 6 << " " << 0 << std::endl; // Calcula a quantidade de vertices e faces


	for (int i = 0; i < nx; i++) { // Declarando os pontos centrais de cada voxel
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].show) {
					outFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
					outFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
				}
			}
		}
	}

	int vertice = 0;

	for (int i = 0; i < nx; i++) { // Declarando as faces
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].show == true) {
					outFile << 4 << " " << vertice*8 + 0 << " " << vertice*8 + 3 << " " << vertice*8 + 2 << " " << vertice*8 + 1 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0 " << std::endl;
					outFile << 4 << " " << vertice*8 + 4 << " " << vertice*8 + 5 << " " << vertice*8 + 6 << " " << vertice*8 + 7 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0 " << std::endl;
					outFile << 4 << " " << vertice*8 + 0 << " " << vertice*8 + 1 << " " << vertice*8 + 5 << " " << vertice*8 + 4 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0 " << std::endl;
					outFile << 4 << " " << vertice*8 + 0 << " " << vertice*8 + 4 << " " << vertice*8 + 7 << " " << vertice*8 + 3 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0 " << std::endl;
					outFile << 4 << " " << vertice*8 + 3 << " " << vertice*8 + 7 << " " << vertice*8 + 6 << " " << vertice*8 + 2 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0 " << std::endl;
					outFile << 4 << " " << vertice*8 + 1 << " " << vertice*8 + 2 << " " << vertice*8 + 6 << " " << vertice*8 + 5 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0 " << std::endl;
					vertice++;
				}
			}
		}
	}
	outFile.close();
}