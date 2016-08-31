#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "IntersectionVector.hpp"
#include "RayTracing.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Lighting.hpp"
#include "Light.hpp"
#include <math.h>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

double taillePixel =3*29.4/1000;

vector<vector<Vector> > rayTracing(const Camera &camera, Scene &scene, Light &light){
//INITIALISATION DE L ECRAN
	//on récupère tous les champs dont on a besoin
	double width=camera.getWidth();
	double height=camera.getHeight();
	double inf=numeric_limits< double >::infinity();//on stocke un double de valeur infini
	Vector eye=camera.getEye();
	Vector orientation=camera.getOrientation();
	Vector target = camera.getTarget();
	Vector normal=eye-target;
   Vector source = light.getPoint();

	//on défini les vecteurs unitaires de base ey, et le vecteur normal à l'écran, normal (ez)
	Vector ey = orientation*(1/sqrt(orientation*orientation));
	normal = normal*(1/sqrt(normal*normal));

	//puis on défini ex en faisant le produit scalaire
	Vector ex(ey.getd2()*normal.getd3()-ey.getd3()*normal.getd2(),ey.getd3()*normal.getd1()-ey.getd1()*normal.getd3(), ey.getd1()*normal.getd2()-ey.getd2()*normal.getd1());	

	//on initialise tout les points à la couleur noir par défaut (rouge=0, vert=0, bleu=0)
	Vector white(255,255,255);
	Vector black(0,0,0) ;
	vector<Vector> black2(width, black);
	vector<vector<Vector> > resultat(height, black2);

//PARCOURS DE L ECRAN 

	for (double i=-height/2; i<height/2; i++){	
		for(double j=-width/2; j<width/2; j++){
			//on calcule les coordonnées du point de l'écran visé
			Vector point=target;
			point=point+ex*j*taillePixel;
			point=point+ey*i*taillePixel;
            
   //ON TROUVE LE POINT DE L ESPACE CORRESPONDANT AU PIXEL
         Sphere sphereVue= Sphere(black, 0., 0., 0., 0., 0.);
         Vector pointVu;
            
			//on garde en mémoire le point d'intersection le plus proche, 
			//en effet si un rayon intersecte 2 sphères, 
			//on voit la couleur de la sphère la plus proche, 
			//pour l'instant il n'y a pas d'intersection, on initialise à l'infinie.
		   double dist=inf;

			//on stocke la direction point de l'écran - eye, puis on crée le rayon correspondant
			Vector dir=point-eye;
			Ray r(eye, dir);
				
			//on regarde parmis toutes les sphères si il y a une intersection
			for (set<Sphere, ComparateurSphere>::iterator it = scene.getScene().begin() ; it != scene.getScene().end(); ++it){
				Sphere s=*it;
				Vector intersection = intersectionVector(r, s);
				if( intersection.getd1()!=inf){ 		     //on regarde si il y a intersection
					double dist2=(eye-intersection)*(eye-intersection);//on calcul la distance de l'oeil au point d'intersection
					if(dist2<dist){		     //si le point est plus près que l'ancien point d'intersection on le met à jour
						dist=dist2;
						pointVu=intersection;
                   				sphereVue=s;
               				}
            			}		
         		}
               
		 /*S'il y a bien une sphere a cet endroit (la camera voit une sphere et non le fond noir de l image), on calcule
		       sa couleur. */
		if (dist==inf) {
			resultat[height/2+i][width/2+j]=white;
		}
		 else {
			    Ray rayonLumineux= Ray(source, pointVu-source);
			       Vector normaleVue=pointVu-sphereVue.getCentre();
			       Vector color=lighting(pointVu,normaleVue,light,camera, sphereVue);//on calcule la couleur du point
			       resultat[height/2+i][width/2+j]=color;
		 }
      }
   }
   return resultat;
}
