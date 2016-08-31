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

using namespace std;

int main(){
	//on construit l'objet scene
	Vector centre(0,0,0);
	Sphere s(centre, 7, 0, 255,0, 0);
	//Vector* v2= new Vector(1,2,1);
	//Sphere* s2=new Sphere(*v2, 1, 2,2,2);
	Scene scene;
	scene.add(s);
	//scene->add(*s2);

	//on construit l'objet light
	Vector l(0,8,0);
	Light light(l, 255,255,255);

	//on construit l'onjet camera
	Vector target(0,-10,0);
	Vector eye(0,8,0);
	Vector up(0,0,1);
	Camera camera(eye, target,up,1000, 1000);

	//cout<<"bug ?"<<endl;
	vector< vector< Vector> > color= rayTracing(camera, scene, light);
	//cout<<"bug 4"<<endl;

	int height=color.size();
	//cout<<height<<endl;
	int width=color[0].size();
	//cout<<"width :"<<endl;
	//cout<<width<<endl;

	/*for (int i=0; i<height; i++)
		for(int j=0; j<width; j++){
			color[i][j].print();
		}
	cout<<endl;*/

	bitmap_image image(height,width);

       for (unsigned int x = 0; x < height; ++x){

      	  for (unsigned int y = 0; y < width; ++y){
	        image.set_pixel(x,y, color[x][y].getd1(), color[x][y].getd2(), color[x][y].getd3());
	  }
       }

     image.save_image("test09_color_map_image.bmp");

	return 0;
}
