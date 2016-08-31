#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "IntersectionVector.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main(){
	Vector pointRay(0,0,-1.5);
	Vector pointS(0,0,0);
	Vector dir(0,0,1);
	Sphere s(pointS, 1, 0, 0, 0);
	Ray r(pointRay, dir);
	
	Vector v =intersectionVector(r, s);
	
	v.print();
	double inf=numeric_limits< double >::infinity();
	bool b=v.getd1()==inf;
	cout<<b<<endl;
	if(b)
		cout<<"il n'y a pas d'intersection"<<endl;

}
