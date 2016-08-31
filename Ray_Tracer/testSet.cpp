#include <iostream>
#include "Vector.hpp"
#include <set>

int main ()
{
  std::set<std::string> s;
  std::cout << "Adding 'Hello' and 'World' to the set twice" << std::endl;
  
  Vector* v = new Vector(1,1,1);
  std::set<Vector>* sv=new std::set<Vector>();
  Vector v2=*v;
  sv->insert(v2);
  s.insert("Hello");
  s.insert("World");
  s.insert("Hello");
  s.insert("World");
  
  std::cout << "Set contains:";
  while (!s.empty()) {
    std::cout << ' ' << *s.begin();
    s.erase(s.begin());
  }
  
  return 0;
}
