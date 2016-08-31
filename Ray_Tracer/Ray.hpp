#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"

class Ray {

public:
	Ray(Vector V1, Vector V2);
	~Ray();
	void print() const;
	Vector getPoint() const;
	Vector getDir() const;

private:
	Vector point;
	Vector direction;
	
};


