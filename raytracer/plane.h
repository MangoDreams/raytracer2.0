#ifndef _Plane_H
#define _Plane_H

#include "Object3D.h"

class Plane : public Object3D{

public:
	Plane(Vec3f& normal, float d, Material* material);
	~Plane();
	bool intersect(const Ray& r, Hit& h, float tmin);
	

private:
	Vec3f _normal;
	float _d;
};

#endif