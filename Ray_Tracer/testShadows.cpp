#include "Affichage.hpp"
#include "Camera.hpp"
#include "IntersectionVector.hpp"
#include "Light.hpp"
#include "Lighting.hpp"
#include "Ray.hpp"
#include "Shadows.hpp"
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

	//cout<<"bug ?"<<endl;
	vector< vector< Vector> > color= shadows(camera, scene, light);
	//Ray ray(eye, centre-eye);
	//Vector color2 = shadows(camera, scene, light, ray);
	//color2.print();
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
