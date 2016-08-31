#pragma once

#include "Camera.hpp"
#include "IntersectionVector.hpp"
#include "Light.hpp"
#include "Lighting.hpp"
#include "Ray.hpp"
#include "RayTracing.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <math.h>
#include <iostream>
#include <limits>
#include <vector>


vector<vector<Vector> > rayTracing(const Camera &camera, Scene &scene, Light &light);
