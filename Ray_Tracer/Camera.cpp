#include "Vector.hpp"
#include "Camera.hpp"
#include <iostream>

using namespace std;

Camera::Camera(Vector e, Vector t, Vector o, double w, double h){
	eye=e;
	target=t;
	orientation=o;
	width=w;
	height=h;
}

Camera::~Camera(){
}

double Camera::getWidth() const{
	return width;
}

const Vector &Camera::getTarget() const{
	return target;
}

const Vector &Camera::getOrientation() const{
	return orientation;
}

double Camera::getHeight() const{
	return height;
}

const Vector &Camera::getEye() const{
	return eye;
}

void Camera::print() const{
	cout<<"eye=";eye.print();
	cout<<"target=";target.print();
	cout<<"orientation=";orientation.print();
	cout<<"width : "<< width<<endl;
	cout<<"height :"<<height<<endl;
}


