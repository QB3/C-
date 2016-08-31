#include "Vector.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include <iostream>
#include <set>

using namespace std;

Scene::Scene() : scene() {
}

Scene::~Scene(){
//	if(!scene.empty()) delete scene;
	scene.clear();
}

bool Scene::empty(){
	return scene.empty();
}

/*iterator Scene::begin(){
	return scene.begin();
}

iterator Scene::end(){
	return scene.end();
}
*/
int Scene::size(){
	return scene.size();
}

void Scene::print(){
	set<Sphere>::iterator it=scene.begin();
	while(it!=(scene).end())
		{Sphere s=*it; s.print(); it++;}
}

set<Sphere, ComparateurSphere> Scene::getScene(){
	return scene;
}


void Scene::add(Sphere s){
	scene.insert(s);
}



