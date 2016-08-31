all: testRayTracing1 testRayTracing2 testRayTracing3 testShadows1 testShadows2 testShadows3 testReflection1 testReflection2 testReflection3 testMPI1 testMPI2 testMPI3

testRayTracing1:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp RayTracing.cpp RayTracing.hpp testRayTracing1.cpp
	g++ testRayTracing1.cpp RayTracing.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testRayTracing1

testRayTracing2:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp RayTracing.cpp RayTracing.hpp testRayTracing2.cpp
	g++ testRayTracing2.cpp RayTracing.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testRayTracing2

testRayTracing3:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp RayTracing.cpp RayTracing.hpp testRayTracing3.cpp
	g++ testRayTracing3.cpp RayTracing.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testRayTracing3

testShadows1:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp Shadows.cpp Shadows.hpp testShadows1.cpp
	g++ testShadows1.cpp Shadows.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testShadows1

testShadows2:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp Shadows.cpp Shadows.hpp testShadows2.cpp
	g++ testShadows2.cpp Shadows.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testShadows2

testShadows3:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp Shadows.cpp Shadows.hpp testShadows3.cpp
	g++ testShadows3.cpp Shadows.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testShadows3

testReflection1:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp Reflection.cpp Reflection.hpp testReflection1.cpp
	g++ testReflection1.cpp Reflection.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testReflection1

testReflection2:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp Reflection.cpp Reflection.hpp testReflection2.cpp
	g++ testReflection2.cpp Reflection.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testReflection2

testReflection3:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp Reflection.cpp Reflection.hpp testReflection3.cpp
	g++ testReflection3.cpp Reflection.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testReflection3

testMPI1:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp MPI.cpp MPI.hpp testMPI1.cpp
	mpic++ testMPI1.cpp MPI.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testMPI1.exe

testMPI2:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp MPI.cpp MPI.hpp testMPI2.cpp
	mpic++ testMPI2.cpp MPI.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testMPI2.exe

testMPI3:  Vector.hpp Vector.cpp Ray.cpp Ray.hpp Light.cpp Light.hpp Lighting.cpp Lighting.hpp ComparateurSphere.cpp Sphere.hpp Sphere.cpp IntersectionVector.cpp IntersectionVector.hpp Scene.cpp Scene.hpp Camera.hpp Camera.cpp MPI.cpp MPI.hpp testMPI3.cpp
	mpic++ testMPI3.cpp MPI.cpp Vector.cpp Ray.cpp Light.cpp IntersectionVector.cpp Camera.cpp Sphere.cpp Scene.cpp ComparateurSphere.cpp Lighting.cpp -o testMPI3.exe


clean:
	rm -f  testRayTracing1 testRayTracing2 testRayTracing3 testShadows1 testShadows2 testShadows3 testReflection1 testReflection2 testReflection3 testMPI1 testMPI2 testMPI3
