#pragma once

#include <iostream>
#include "Vector.hpp"

using namespace std;

class Camera {

public:
	Camera(Vector e, Vector t, Vector o, double w, double h);
	~Camera();
	void print() const;
	const Vector &getEye() const;
	const Vector &getTarget() const;
	const Vector &getOrientation() const;
	double getWidth() const;
	double getHeight() const;

private:
	Vector eye;
	Vector target;
	Vector orientation;
	double width;
	double height;
};


