#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "IntersectionVector.hpp"
#include <math.h>
#include <iostream>
#include <limits>

using namespace std;

Vector intersectionVector(const Ray &r,const Sphere &s){
	Vector point=r.getPoint();
	Vector dir=r.getDir();
	Vector centre=s.getCentre();
	double rayon=s.getRayon();
	double a=dir*dir;
	double b=2*((point-centre)*dir);
	double c=(point-centre)*(point-centre)-rayon*rayon;
	
	double delta=b*b-4*a*c;

	
	if(delta<0)
		return Vector(numeric_limits< double >::infinity(), numeric_limits< double >::infinity(),numeric_limits< double >::infinity());
	else{
		double t1=(-b-sqrt(delta))/(2*a);
		//cout<<"t1 :"<<t1<<endl;
		double t2=(-b+sqrt(delta))/(2*a);
		/*cout<<"t2 :"<<t2<<endl;
		cout<<"dir :";dir.print();
		cout<<"point :";point.print();;
		Vector v1 = point+dir*t1;
		Vector v2 = point+dir*t2;
		cout<<"v1=";v1.print();
		cout<<"v2=";v2.print();*/
		if (t1<=0)//
			return Vector(numeric_limits< double >::infinity(), numeric_limits< double >::infinity(),numeric_limits< double >::infinity());
		else if (t2<=0)//
			return Vector(numeric_limits< double >::infinity(), numeric_limits< double >::infinity(),numeric_limits< double >::infinity());
		else if (t1<t2)
			return (point+dir*t1);
		else
			return (point+dir*t2);
	}
}

