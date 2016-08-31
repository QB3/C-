//#include <iostream>
#include "Vector.hpp"
using namespace std;

//je fais des tests

int main(){

Vector* v1 = new Vector(1, 1, 1);
Vector* v2 = new Vector(1, 1, 1);
Vector v3 = v1->add(*v2);
Vector v4=Vector(2,2,2);
v4=v4.mult(4);
Vector v5=(*v2)-(v3*(-1));

bool b1=(*v1).equals(*v2);
bool b2=(*v1)==(*v2);

if(b2==true){
	std::cout << "ça marche" << endl;
}

v1->print();
v3.print();
v4.print();
v5.print();

double d = (*v1)*(*v1);
cout<<d<<endl;
return 0;
}
