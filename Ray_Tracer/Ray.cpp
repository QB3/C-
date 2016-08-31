#include "Vector.hpp"
#include "Ray.hpp"
#include <iostream>
using namespace std;

Ray::Ray(Vector V1, Vector V2){
	point=V1;
	direction=V2;
}

Ray::~Ray(){
}

void Ray::print() const{
	point.print();
	direction.print();
}

Vector Ray::getPoint() const{
	return point;
}

Vector Ray::getDir() const{
	return direction;
}

