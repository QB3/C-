/*#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Shadows.hpp"
#include "Light.hpp"
#include <vector>

	vector<vector<Vector> > shadows(const Camera &camera,Scene &scene, Light &light);*/

#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "IntersectionVector.hpp"
#include "Shadows.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
//#include "Lighting.hpp"
#include "Light.hpp"
#include "Reflection.hpp"
#include <vector>

  	 vector<vector<Vector> > shadows(Camera camera, Scene scene, Light light);
	 Vector shadows(Camera &camera, Scene &scene, Light &light, Ray &ray);
   //bool rayonPasIntersecte(Vector v, Scene s, Ray r);
   //Vector pointReflechissant(Vector pointVu, Light light, Sphere sphere);
