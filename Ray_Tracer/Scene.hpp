#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Sphere.hpp"
#include "ComparateurSphere.cpp"
#include <set>



using namespace std;

class Scene {

public:
	Scene();
	~Scene();
	void add(Sphere s);
	bool empty();
/*	iterator begin();
	iterator end();
*/	int size();
	void print();
	set<Sphere, ComparateurSphere> getScene();

private:
	set<Sphere, ComparateurSphere> scene;
	
};



