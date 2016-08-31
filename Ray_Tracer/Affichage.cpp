//#ifndef INCLUDE_BITMAP_IMAGE_HPP
//#define INCLUDE_BITMAP_IMAGE_HPP

#include "Affichage.hpp"
#include "Camera.hpp"
#include "IntersectionVector.hpp"
#include "Light.hpp"
#include "Lighting.hpp"
#include "Ray.hpp"
#include "RayTracing.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <math.h>
#include <iostream>
#include <limits>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "bitmap_image.hpp"
using namespace std;


void afficher()
{

//on construit l'objet scene
	Vector* centre= new Vector(0,0,0);
	Sphere* s=new Sphere(*centre, 1, 1,0,0);
	Scene* scene=new Scene();
	scene->add(*s);

	//on construit l'objet light
	Vector* l = new Vector(0,2,0);
	Light* light = new Light(*l, 1,1,1);

	//on construit l'onjet camera
	Vector* target=new Vector(0,-7,0);
	Vector* eye = new Vector(0,3,0);
	Vector* up = new Vector(0,0,1);
	Camera* camera = new Camera(*eye, *target,*up,1000,1000);
	
	vector< vector< Vector> > color= rayTracing(*camera, *scene, *light);


   const unsigned int heigth = color.size();
   const unsigned int width = color[0].size();


   //const unsigned int heigth = 1000;	
   //const unsigned int width = 1000;

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
	afficher();
}

