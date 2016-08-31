//#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"
using namespace std;

//tests
int main(){
	Vector* v1 = new Vector(1, 1, 1);
	Vector* v2 = new Vector(1, 1, 1);
	Ray* r = new Ray(*v1, *v2);
	r->print();
	Vector v3 = v1->add(*v2);
	Vector v4=Vector(2,2,2);
	v4=v4.mult(4);
	Ray* r2 = new Ray(v3, v4);
	r2->print();
	Vector v5=r->getDir();
	cout<<"direction :";
	v5.print();
}

