#include "Vector.hpp"
#include "Light.hpp"
#include <iostream>

using namespace std;

Light::Light(Vector v, double r, double g, double b){
	point=v;
	red=r;
	green=g;
	blue=b;
}

Light::~Light(){
	
}

Vector Light::getPoint() const{
	return point;
}

double Light::getRed() const{
	return red;
}

double Light::getGreen() const{
	return green;
}

double Light::getBlue() const{
	return blue;
}

void Light::print() const{
	point.print();
	cout<<"red="<<red<<endl;
	cout<<"green="<<green<<endl;
	cout<<"blue="<<blue<<endl;
}
