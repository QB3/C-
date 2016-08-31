#include "Vector.hpp"
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
#include <mpi.h>
#include <stdio.h>

using namespace std;

double taillePixel =3*29.4/1000;

/* Cette fonction renvoit true si le rayon atteint le point et false si une sphere fait obstacle et que le point est donc
ombrage. */
bool rayonPasIntersecte(Vector v, Scene s, Ray r) {
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
	if (dist==inf) {
		resultat[height/2+i][width/2+j]=white;
	}
         else {
		    Ray rayonLumineux= Ray(source, pointVu-source);
		    //bool pasIntersecte=rayonPasIntersecte(pointVu, scene, rayonLumineux);
		    //if(pasIntersecte) {
		       Vector normaleVue=pointVu-sphereVue.getCentre();
		       Vector color=lighting(pointVu,normaleVue,light,camera, sphereVue);//on calcule la couleur du point
			//color.print();
		       //double reflect=sphereVue.getReflection();
		       //double coeff=1-reflect;
		       resultat[height/2+i][width/2+j]=color;//.mult(coeff);
            
/*                  
                  
		// REFLECTION	: sur chaque sphere, on trouve le point eventuel pour lequel la lumiere emise par light se reflechit en
                  //direction de pointVu et on ajoute cette contribution a light si aucune autre sphere n intersecte les rayons. 
				for (set<Sphere, ComparateurSphere>::iterator it2 = scene.getScene().begin() ; it2 != scene.getScene().end(); ++it2){								
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
               } 
*/
            //}
         }
      }
   }
   return resultat;
}

















vector<vector<Vector> > ReflectionMPI(Camera camera, Scene scene, Light light)
{
// Initialisation du MPI
	int rank, numprocs, n;
	double tableauCamera[17];
	MPI_Status status;
	MPI_Request Request;

	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

// Le processeur 0 transmet le nombre de processeurs n et les données permettant de construire scene à chaque processeur
//On considere que argv est un tableau de doubles représentant les 7 parametres de chacune des spheres de scene.
	if (rank ==0) {
		n=scene.size();
		tableauCamera[0]= light.getPoint().getd1();
		tableauCamera[1]= light.getPoint().getd2();
		tableauCamera[2]= light.getPoint().getd3();
		tableauCamera[3]= light.getRed();
		tableauCamera[4]= light.getGreen();
		tableauCamera[5]= light.getBlue();
		tableauCamera[6]= camera.getEye().getd1();
		tableauCamera[7]= camera.getEye().getd2();
		tableauCamera[8]= camera.getEye().getd3();
		tableauCamera[9]= camera.getTarget().getd1();
		tableauCamera[10]= camera.getTarget().getd2();
		tableauCamera[11]= camera.getTarget().getd3();
		tableauCamera[12]= camera.getOrientation().getd1();
		tableauCamera[13]= camera.getOrientation().getd2();
		tableauCamera[14]= camera.getOrientation().getd3();
		tableauCamera[15]= camera.getWidth();
		tableauCamera[16]= camera.getHeight();
		std::cout<<"n="<<n<<std::endl;

	}

	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

	double tableauScene[8*n];

	if (rank ==0) {
		int i=0;
		for(set<Sphere, ComparateurSphere>::iterator it=scene.getScene().begin(); it!=scene.getScene().end(); it++) {
			tableauScene[8*i]=(*it).getCentre().getd1();
			tableauScene[8*i+1]=(*it).getCentre().getd2();
			tableauScene[8*i+2]=(*it).getCentre().getd3();
			tableauScene[8*i+3]=(*it).getRayon();
			tableauScene[8*i+4]=(*it).getRed();
			tableauScene[8*i+5]=(*it).getGreen();
			tableauScene[8*i+6]=(*it).getBlue();
			tableauScene[8*i+7]=(*it).getReflection();
			i++;
		}
	}

	MPI_Bcast(tableauScene, 8*n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(tableauCamera, 17, MPI_DOUBLE, 0, MPI_COMM_WORLD);

//Chaque processeur construit scene 
	Scene sceneLocale= Scene();
	for(int i=0; i<n; i++) {
		Vector v=Vector(tableauScene[8*i],tableauScene[8*i+1],tableauScene[8*i+2]);
		Sphere s=Sphere(v, tableauScene[8*i+3],tableauScene[8*i+4],tableauScene[8*i+5],tableauScene[8*i+6],tableauScene[8*i+7]);
		sceneLocale.add(s);
	}

//On fait de même avec la camera et light. Ils sont transmis par le processeur 0 puis construits par chaque processeur
//La différence vient du fait que le champ de l'image diffère d'un processeur à l'autre afin que chaque processeur calcule seulement une partie de l'image.
//On partage l'image en faisant des trnaches suivant la hauteur.
	Vector vlight= Vector(tableauCamera[0], tableauCamera[1], tableauCamera[2]); 
	Light lightLocale=Light(vlight, tableauCamera[3], tableauCamera[4], tableauCamera[5]);
	Vector e= Vector(tableauCamera[6], tableauCamera[7], tableauCamera[8]);
	Vector t= Vector(tableauCamera[9], tableauCamera[10], tableauCamera[11]);
	Vector o= Vector(tableauCamera[12], tableauCamera[13], tableauCamera[14]);
        int width= (int) tableauCamera[15];
        int height= (int) tableauCamera[16];
	Camera cameraLocale=Camera(e, t+o.mult(taillePixel*(rank-numprocs/2+1/2)*height/numprocs), o, width, height/numprocs);
std::cout<<numprocs<<std::endl;

//Chaque processeur calcule une partie de l'image
	vector<vector<Vector> > resultatLocal=Reflection(cameraLocale, sceneLocale, lightLocale);
	//for(int i=0; i<10; i++) resultatLocal[rank][i].print();
//On transforme resultatLocal en un format que l'on peut envoyer par MPI.
        int taille = 3*width*height/numprocs;
        double resultatLocalATransferer[taille];

      	for (int ligne=0; ligne<height/numprocs; ligne ++) {
		std::cout<<"Ligne "<<ligne<<" :"<<std::endl;
                for(int colonne=0; colonne<width; colonne ++) {
                        resultatLocalATransferer[ligne*width*3+colonne*3]=resultatLocal[ligne][colonne].getd1();
                        resultatLocalATransferer[ligne*width*3+colonne*3+1]=resultatLocal[ligne][colonne].getd2();
                        resultatLocalATransferer[ligne*width*3+colonne*3+2]=resultatLocal[ligne][colonne].getd3();

                }
        }
	double resultatTransfere[taille*numprocs];
//if (rank==0) resultat=(int *)malloc(taille*numprocs*sizeof(double)); 
	MPI_Gather(resultatLocalATransferer, taille, MPI_DOUBLE, resultatTransfere, taille, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	Vector black(0,0,0) ;
	vector<Vector> black2(width, black);
	vector<vector<Vector> > resultat(height, black2);
	if (rank==0){
        	for (int ligne=0; ligne<height; ligne ++) {
			//std::cout<<"ligne:"<<ligne<<std::endl;
                	for(int colonne=0; colonne<width; colonne ++) {
				//std::cout<<"colonne: "<<colonne<<std::endl;
				Vector temp=Vector(resultatTransfere[ligne*width*3+colonne*3], resultatTransfere[ligne*width*3+colonne*3+1], resultatTransfere[ligne*width*3+colonne*3+2]);
                                resultat[ligne][colonne]=temp;

				}
			}	
while(resultat[height-1][width-1]==black) {}	           
//if(rank==3) {resultatLocal[10][10].print();resultatLocal[20][20].print(); return resultatLocal; }
 return resultat; }                        
}
