//#include <iostream>
#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
using namespace std;

int main(){
Vector* v= new Vector(1,2,1);
Sphere* s=new Sphere(*v, .3, 2,2,2, .5);
Vector* v2= new Vector(1,2,1);
Sphere* s2=new Sphere(*v2, 1, 2,2,2);
s->print();
std::cout<<"s<s2: "<<((*s)<(*s2))<<std::endl;
bool b=((*s)<(*s2));
if (b==true) std::cout<<"ça marche 1!"<<std::endl;
bool b2=(*s2)<(*s);
if (b2==false) std::cout<<"ça marche 2!"<<std::endl;
s->print();
s2->print();

Vector v3=s->getCentre();
v3.print();
std::cout<<v3.getd1()<<std::endl;
double d=v3.getd1();
std::cout<<d<<std::endl;

//test ==
Sphere* s5= new Sphere(*v, .3, 2,2,2);
bool b3=(*s5)==(*s);
if(b3)
	cout <<"equals marche"<<endl;
else
	cout<<"equals ne marche pas"<<endl;

double r=s2->getReflection();
std::cout<<"Reflexion="<<r<<std::endl;
}

