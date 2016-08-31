//#ifndef INCLUDE_BITMAP_IMAGE_HPP
//#define INCLUDE_BITMAP_IMAGE_HPP

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Vector.hpp"
#include "Afficher.hpp"

#include "bitmap_image.hpp"
using namespace std;


void afficher(/*vector<vector<Vector> > color*/){

   const unsigned int heigth = 1000;
   const unsigned int width = 1000;

   bitmap_image image(heigth,width);

   for (unsigned int x = 0; x < heigth; ++x)
   {
      for (unsigned int y = 0; y < width; ++y)
      {
         image.set_pixel(x,y,255, 255, 255);
      }
   }

   image.save_image("test09_color_map_image.bmp");
}

int main(){
	/*vector< vector <Vector> > v;
	vector<Vector> v2;
	Vector *white = new Vector(255, 255, 255);
	v2.push_back(*white);
	v.push_back(v2);
	afficher(v);*/
	afficher();
}
