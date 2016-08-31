#pragma once

#include <iostream>
#include "Vector.hpp"
//#include "Light.hpp"


using namespace std;

class Light {

public:
	Light(Vector v, double r, double g, double b);
	~Light();
	void print() const;
	Vector getPoint() const;
	double getRed() const;
	double getGreen() const;
	double getBlue() const;

private:
	Vector point;
	double red;
	double green;
	double blue;
	
};


