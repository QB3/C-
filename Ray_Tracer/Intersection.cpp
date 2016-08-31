#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Intersection.hpp"
#include <math.h>
#include <iostream>

using namespace std;

bool intersection(Ray r, Sphere s){
	Vector point=r.getPoint();
	Vector dir=r.getDir();
	Vector centre=s.getCentre();
	double rayon=s.getRayon();

	double a=dir*dir;
	double b=2*((point-centre)*dir);
	double c=(point-centre)*(point-centre)-rayon*rayon;
	
	double delta=b*b-4*a*c;

if(delta<0)
	return false;
else return true;

}



