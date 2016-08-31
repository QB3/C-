#include "Vector.hpp"
#include "Light.hpp"
#include <iostream>



int main(){
	Vector* v = new Vector(1,1,1);
	Light* l = new Light(*v, 255,255,255);
	double d=l->getGreen();
	std::cout<<d<<endl;
	l->print();
}
