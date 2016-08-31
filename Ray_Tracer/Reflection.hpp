#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "IntersectionVector.hpp"
#include "Shadows.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Lighting.hpp"
#include "Light.hpp"
#include "Reflection.hpp"
#include <vector>

   vector<vector<Vector> > reflection(Camera camera, Scene scene, Light light);
