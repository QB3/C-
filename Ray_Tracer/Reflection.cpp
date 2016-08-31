#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "IntersectionVector.hpp"
#include "Reflection.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Lighting.hpp"
#include "Light.hpp"
#include <math.h>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

double taillePixelShadows =3*29.4/1000;

vector<vector<Vector> > reflection(Camera camera, Scene scene, Light light){
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
	Vector test(255,0,0);
	vector<Vector> black2(width, test);
	vector<vector<Vector> > resultat(height, black2);

//PARCOURS DE L ECRAN 

	for (double i=-height/2; i<height/2; i++){	
		for(double j=-width/2; j<width/2; j++){
			//on calcule les coordonnées du point de l'écran visé
			Vector point=target;
			point=point+ex*j*taillePixelShadows;
			point=point+ey*i*taillePixelShadows;
            
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
               
			 //S'il y a bien une sphere a cet endroit 
			//(la camera voit une sphere et non le fond noir de l image), 
			//on calcule sa couleur
			if (dist==inf) {
				resultat[height/2+i][width/2+j]=white;
			}
			 else {
				double reflection = sphereVue.getReflection();
				Vector colorSeen(0,0,0);
				Vector colorRef(0,0,0);
				for (set<Sphere, ComparateurSphere>::iterator it2 = scene.getScene().begin() ; it2 != scene.getScene().end(); 									++it2){		
					Sphere sphere2= (*it2);	
					//cout<<"sphereVue : ";sphereVue.print();
					//cout<<"it : ";it2->print();				
					if(!(sphere2==sphereVue)){
						//cout<<"bug 10";
						Vector rayonLumineux = pointVu-source;
						Ray r2(source, rayonLumineux);
						Vector intersection2 = intersectionVector(r2, *it2);		
						//on vérifie qu'il y a intersection
						bool b =intersection2.getd1()!=inf;
						if (b){
							double dist3=(pointVu-source)*(pointVu-source);
							double dist4=(intersection2-source)*(intersection2-source);
							//et que l'intersection a bien lieu (strictement) avant que le rayon atteigne intersection
							//on se prémunit donc du cas ou it=it2
							bool b2= dist4<dist3;
							bool b3=intersection2==pointVu;
							if (b2&&!b3){
								//resultat[height/2+i][width/2+j]=black;
								colorSeen=black;
								break;
							}
						}
					}
				
					Vector dir = pointVu-source;
				       Vector normaleVue=pointVu-sphereVue.getCentre();
					double decision = dir*normaleVue;
					if (decision >0){
						colorSeen=black;
						//resultat[height/2+i][width/2+j]=black;
					}
						
					else{
					       //Vector color=lighting(pointVu,normaleVue,light,camera, sphereVue);//on calcule la couleur du point
					       //resultat[height/2+i][width/2+j]=color;
						colorSeen=lighting(pointVu,normaleVue,light,camera, sphereVue);
					}
				}
				//colorSeen.print();
				
				//on refait la même chose qu'avant, on regarde quelle est la sphere la plus proche.
				Vector L=eye-pointVu;
				L=L*(1/sqrt(L*L));
				Vector N=pointVu-sphereVue.getCentre();
				N=N*(1/sqrt(N*N));
				Vector dirReflechie = N*2*(N*L)-L;
				Ray rayonReflechi = Ray(pointVu, dirReflechie);
				double dist4=inf;
				//colorRef=shadows(camera, scene, light, rayonReflechi);
				 Sphere sphereVue3= Sphere(black, 0., 0., 0., 0., 0.);
				for (set<Sphere, ComparateurSphere>::iterator it2 = scene.getScene().begin() ; it2 != scene.getScene().end(); 									++it2){
					Sphere s=*it2;
					bool b4=s==sphereVue;
					if(!b4){
						Vector intersection3 = intersectionVector(rayonReflechi, s);
						if( intersection3.getd1()!=inf){ 		     //on regarde si il y a intersection
							double dist5=(pointVu-intersection3)*(pointVu-intersection3);//on calcule la distance de l'oeil au point d'intersection
							if(dist5<dist4){		     //si le point est plus près que l'ancien point d'intersection on le met à jour
								dist4=dist5;
								pointVu=intersection3;
				   				sphereVue3=s;
		       					}
            					}		
         				}
					
				}
				if(dist4!=inf){
					colorRef=lighting(pointVu, N, light, camera, sphereVue3);
				}
				resultat[height/2+i][width/2+j]=colorSeen*(1-reflection)+colorRef*reflection;
            			}
      }
   }
   return resultat;
}

/*#include "Vector.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "IntersectionVector.hpp"
#include "Shadows.hpp"
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

/* Cette fonction renvoit true si le rayon atteint le point et false si une sphere fait obstacle et que le point est donc
ombrage. */
/*bool rayonPasIntersecte(Vector v, Scene s, Ray r) {
   bool pasIntersecte=true;
   Vector source= r.getPoint();
   double dist=(v-source)*(v-source);
   double inf=numeric_limits< double >::infinity();//on stocke un double de valeur infini
   for (set<Sphere, ComparateurSphere>::iterator it = s.getScene().begin() ; it != s.getScene().end(); ++it){
      Vector intersection = intersectionVector(r, *it);
		bool b =intersection.getd1()!=inf;
      if (b){
			double dist2=(intersection-source)*(intersection-source);
			//et que l'intersection a bien lieu (strictement) avant que le rayon atteigne intersection
			//on se prémunit donc du cas ou les deux points sont les memes
			bool plusPres= dist2<dist; 
         if(plusPres) pasIntersecte=false;
         break;
      }
   }
   return pasIntersecte;
}
// TODO
Vector pointReflechissant(Vector pointVu, Light light, Sphere sphere) {
	Vector source = light.getPoint();
	Vector centre = sphere.getCentre();
	Vector l=source-centre;
	double distL=sqrt(l*l);
	Vector r= pointVu-centre;
	double distR=sqrt(r*r);
	Vector n=r*distR+l*distL;
	return n*(1/sqrt(n*n));
}     





vector<vector<Vector> > Reflection(Camera camera, Scene scene, Light light){
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
	/*if (dist==inf) {
		resultat[height/2+i][width/2+j]=white;
	}
         else {
		    Ray rayonLumineux= Ray(source, pointVu-source);
		    //bool pasIntersecte=rayonPasIntersecte(pointVu, scene, rayonLumineux);
		    //if(pasIntersecte) {
		       Vector normaleVue=pointVu-sphereVue.getCentre();
		       Vector color=lighting(pointVu,normaleVue,light,camera, sphereVue);//on calcule la couleur du point
			color.print();
		       //double reflect=sphereVue.getReflection();
		       //double coeff=1-reflect;
		       resultat[height/2+i][width/2+j]=color;//.mult(coeff);
                        
                  
		// REFLECTION	: sur chaque sphere, on trouve le point eventuel pour lequel la lumiere emise par light se reflechit en
                  //direction de pointVu et on ajoute cette contribution a light si aucune autre sphere n intersecte les rayons. 
		/*for (set<Sphere, ComparateurSphere>::iterator it2 = scene.getScene().begin() ; it2 != scene.getScene().end(); ++it2){								
		       //calculer les coordonnees du point de la sphere it2 qui se reflete en pointVu.
		       Sphere s2=*it2;
		       Vector pointRef= pointReflechissant(pointVu, light, s2);
		       //on verifie que ce point existe
		       if(pointRef.getd1()!=inf) {
		          //on verifie que les rayons ne sont pas intersectes et on prend en compte les ombres sur le point 
		          //reflechissant. 
		          Ray avantReflection= Ray(source, pointRef-source);
		          Ray apresReflection= Ray(pointRef, pointVu-pointRef);
		          if(rayonPasIntersecte(pointRef, scene, avantReflection) && rayonPasIntersecte(pointVu, scene, 
		                apresReflection) ) {
		             Vector normalePointRef=pointRef-s2.getCentre();
		             Vector color2=lighting(pointRef, normalePointRef, light, camera);     
						      resultat[height/2+i][width/2+j]=resultat[height/2+i][width/2+j]+color2.mult(reflect) ;
			  }
                  	}
               } */
            //}
         /*}
      }
   }
   return resultat;
}

//int main(){}
*/



