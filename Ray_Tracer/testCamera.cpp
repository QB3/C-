#include "Vector.hpp"
#include "Camera.hpp"
#include <iostream>

using namespace std;

int main(){
	Vector* e = new Vector(1,1,1);
	Vector* t = new Vector(2,2,2);
	Vector* o = new Vector(3,6,8);
	Camera* c= new Camera(*e, *t, *o, 5, 3);
	c->print();
}
