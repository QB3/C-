#include "Vector.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Lighting.hpp"
#include <iostream>
#include <math.h> 

using namespace std;

int main(){
	Vector* point=new Vector(0,0,0);
	Vector* N=new Vector(0,0,1);
	Vector* l = new Vector(1,0,2);
	Vector* eye = new Vector(-2,0,2);
	Vector* n = new Vector(0,0,0);
	Light* light=new Light(*l, 255,255,255);
	Camera* camera = new Camera(*eye, *n,*n,3,3);
	Vector color=lighting(*point, *N, *light, *camera);
	color.print();
}
