#include "Vector.hpp"
#include <iostream>
using namespace std;


Vector::Vector(){
	d1=0;
	d2=0;
	d3=0;
}

Vector::Vector(double D1, double D2, double D3){

	d1=D1;
	d2=D2;
	d3=D3;

}

Vector::~Vector() {
}

double Vector::getd1() const{
	return d1;
}

double Vector::getd2() const{
	return d2;
}

double Vector::getd3() const{
	return d3;
}

void Vector::print() const {
	cout << "(" << this->getd1() <<", "<< this->getd2() <<", "<< this->getd3() << ")"<<endl;

}

Vector Vector::add(const Vector &v) const{
	return Vector(d1+v.d1, d2+v.d2, d3+v.d3);
}

Vector Vector::mult(double d) const{
	return Vector(d*d1, d*d2, d*d3);
}

bool Vector::equals(Vector b)const{
	return (d1 == b.d1 && d2 == b.d2 && d3 == b.d3);     
}

bool Vector::operator==(const Vector &v)const{
	return equals(v);
}

Vector Vector::operator+(const Vector& v)const{
	Vector vInt=add(v);
	return vInt;
}

Vector Vector::operator-(const Vector &v)const{
	return Vector(d1-v.d1, d2-v.d2, d3-v.d3);
}

Vector Vector::operator*(double d)const{
	return mult(d);
}

double Vector:: operator*(const Vector& v)const{
	return d1*v.d1 + d2*v.d2 + d3*v.d3;
}

