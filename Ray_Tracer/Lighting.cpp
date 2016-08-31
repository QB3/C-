#include "Vector.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Lighting.hpp"
#include "Sphere.hpp"
#include <iostream>
#include <math.h> 
using namespace std;


Vector lighting(const Vector point,Vector N,const Light light,const Camera camera, const Sphere sphere){

	double ka=0.6;
	double kd=0.6;
	double ks=0.1;
	double ia=0.6;
	double alpha=50;

	
	Vector L=light.getPoint()-point;
	L=L*(1/sqrt(L*L));

	Vector V=camera.getEye()-point;
	V=V*(1/sqrt(V*V));
	
	Vector R= N*(N*L)*2-L;
	R=R*(1/sqrt(R*R));

	N=N*(1/sqrt(N*N));

	double idr=sphere.getRed();
	double isr=sphere.getRed();
	
	double idg=sphere.getGreen();
	double isg=sphere.getGreen();

	double idb=sphere.getBlue();
	double isb=sphere.getBlue();

	double puiss=pow(R*V, alpha);

	double Ir=ia*ka+idr*kd*(L*N)+isr*ks*puiss;
	double Ig=ia*ka+idg*kd*(L*N)+isg*ks*puiss;
	double Ib=ia*ka+idb*kd*(L*N)+isb*ks*puiss;

	Vector color(Ir, Ig, Ib);
	return color;

}


