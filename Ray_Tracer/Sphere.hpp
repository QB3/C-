#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"

class Sphere {

public:
	Sphere(Vector v, double d, double r, double g, double b, double reflect=1.);
	~Sphere();
	void print() const;
	Vector getCentre() const;
	double getRayon() const;
	double getReflection() const;
	double getRed() const;
	double getGreen() const;
	double getBlue() const;
	bool inferieur(Sphere s) const;
	bool equals(Sphere s)const;
	bool operator<(const  Sphere s) const;//on peut l'enlever, plus utilisé
	bool operator==(const Sphere s) const;


private:
	Vector centre;
	double rayon;
	double red;
	double green;
	double blue;
	double reflection;
	
};



