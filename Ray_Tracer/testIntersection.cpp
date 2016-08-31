#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Intersection.hpp"
#include <iostream>

using namespace std;

int main(){
	Vector* pointRay=new Vector(0,0,-1.5);
	Vector* pointS=new Vector(0,0,0);
	Vector* dir=new Vector(1,0,0);
	Sphere* s=new Sphere(*pointS, 1, 0, 0, 0);
	Ray* r= new Ray(*pointRay, *dir);
	
	bool b =intersection(*r, *s);
	
	if (b==true)
		cout<<"il y a intersection"<<endl;
	else cout<<"il n'y a pas intersection"<<endl;

	return 0;
}
