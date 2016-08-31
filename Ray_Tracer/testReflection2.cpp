#include "Affichage.hpp"
#include "Camera.hpp"
#include "IntersectionVector.hpp"
#include "Light.hpp"
#include "Lighting.hpp"
#include "Ray.hpp"
#include "Reflection.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <math.h>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(){
	//on construit l'objet scene
	Vector centre(0,0,-4);
	Sphere s(centre, 5, 0, 255,0, 1);
	Vector v2(0,0,8);
	Sphere s2(v2, 1, 255,0,0, 1);
	Scene scene;
	scene.add(s);
	scene.add(s2);

	//on construit l'objet light
	Vector l(0,0,13);
	Light light(l, 255,255,255);

	//on construit l'onjet camera
	Vector target(0,-10,0);
	Vector eye(0,9,7);
	Vector up(0,0,1);
	Camera camera(eye, target,up, 350, 1500);

	//on calcule les couleurs des pixels
	vector< vector< Vector> > color= reflection(camera, scene, light);


	int height=color.size();
	int width=color[0].size();

	//on crée l'image
	bitmap_image image(height,width);

       for (unsigned int x = 0; x < height; ++x){

      	  for (unsigned int y = 0; y < width; ++y){
	        image.set_pixel(x,y, color[x][y].getd1(), color[x][y].getd2(), color[x][y].getd3());
	  }
       }

     image.save_image("testReflection2.bmp");

	return 0;
}
