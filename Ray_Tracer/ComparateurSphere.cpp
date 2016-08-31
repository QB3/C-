#include "Vector.hpp"
#include "Sphere.hpp"

#include <iostream>
#include <set>

struct ComparateurSphere
{
  bool operator()(Sphere s1, Sphere s2) const
  {
    return s1.inferieur(s2);
  }
};
