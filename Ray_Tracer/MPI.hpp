#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include <vector>

	vector<vector<Vector> > Reflection(Camera camera, Scene scene, Light light);
	bool rayonPasIntersecte(Vector v, Scene s, Ray r);
	Vector pointReflechissant(Vector pointVu, Light light, Sphere sphere);
	vector<vector<Vector> > ReflectionMPI(Camera camera, Scene scene, Light light);
