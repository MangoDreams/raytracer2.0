#ifndef _SPHERE_H
#define _SPHERE_H

#include "Object3D.h"

class Sphere: public Object3D{

public:
	Sphere(Vec3f &origin, float r, Material* material);
	~Sphere();
	bool intersect(const Ray &r, Hit &h, float tmin);
	
private:
		float _radius;
		Vec3f _center;
};

#endif