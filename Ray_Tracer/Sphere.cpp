#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include <iostream>
#include <set>


using namespace std;

Sphere::Sphere(Vector v, double d, double r, double g, double b, double reflect){
	centre=v;
	rayon=d;
	red=r;
	green=g;
	blue=b;
	reflection=reflect;
}

Sphere::~Sphere(){
}

Vector Sphere::getCentre() const{
	return centre;
}

double Sphere::getRayon() const{
	return rayon;
}

double Sphere::getReflection() const{
	return reflection;
}

void Sphere::print() const{
	cout<<"centre : ";
	centre.print();
	cout<<"rayon : "<< rayon<<endl;
	cout<<"red="<<red<<endl;
	cout<<"green="<<green<<endl;
	cout<<"blue="<<blue<<endl;
	cout<<"reflection coefficient="<<reflection<<endl;
}

bool Sphere::equals(Sphere s) const{
	return(centre==s.centre&&rayon==s.rayon&&red==s.red&&green==s.green&&blue==s.blue);
}

bool Sphere::operator==(const Sphere v) const{
	return this->equals(v);
}

double Sphere::getRed() const{
	return red;
}
double Sphere::getGreen() const{
	return green;
}
double Sphere::getBlue() const{
	return blue;
}

//on definit une relation d'ordre sur les sphères pour pouvoir creer des ensembles de spheres set qui sera utilisee dans la structure ComparateurSphere.
bool Sphere::inferieur(Sphere s)const{
	Vector centre=this->getCentre();
	double c1=centre.getd1();
	double d1=s.getCentre().getd1();
	if( c1<d1 ) return true;
	else if(centre.getd1()>s.getCentre().getd1()) return false;
	else {
		if(centre.getd2()<s.getCentre().getd2()) return true;
		else if(centre.getd2()>s.getCentre().getd2()) return false;
		else {
			if(centre.getd3()<s.getCentre().getd3()) return true;
			else if(centre.getd3()>s.getCentre().getd3()) return false;
			else {
				if(this->getRayon()<s.getRayon()) return true;
				else return false;}
}}
}
//on peut l'enlever. On ne l'utilise plus pour l'instant.
bool Sphere::operator<(const Sphere s) const{
	return this->inferieur(s);
}


