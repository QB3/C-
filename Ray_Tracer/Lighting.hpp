#pragma once

#include "Vector.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Sphere.hpp"
#include <iostream>

	Vector lighting(const Vector point,const Vector N,const Light light,const Camera camera, const Sphere sphere);
