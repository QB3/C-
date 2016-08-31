#pragma once

#include <iostream>
#include "Vector.hpp"

class Vector {

public:

	Vector(double D1, double D2, double D3);
	Vector();
	~Vector();

	double getd1() const;
	double getd2() const;
	double getd3() const;
	void print() const;
	bool equals(Vector b)const;
	Vector add(const Vector &v) const;
	Vector mult(double d) const;
	bool operator==(const Vector &v)const;
	Vector operator+(const Vector &v)const;
	Vector operator-(const Vector &v)const;
	Vector operator*(double d)const;
	double operator*(const Vector &v)const;
private:

	double d1;
	double d2;
	double d3;
	
};



