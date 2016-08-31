//#include <iostream>
#include "Vector.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"

using namespace std;

int main(){
Vector* v= new Vector(1,2,1);
Sphere* s=new Sphere(*v, .3, 2,2,2);
Vector* v2= new Vector(1,2,1);
Sphere* s2=new Sphere(*v2, 1, 2,2,2);

Scene* scene=new Scene();
scene->add(*s);
scene->add(*s2);
scene->print();
int size=scene->size();
std::cout<<"size:"<<size<<std::endl;

for (set<Sphere, ComparateurSphere>::iterator it = scene->getScene().begin() ; it != scene->getScene().end(); ++it){
	Sphere s=*it;
	s.print();
}


}

