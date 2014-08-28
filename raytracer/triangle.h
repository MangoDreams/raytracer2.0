#ifndef _Triangle_H
#define _Triangle_H

#include "Object3D.h"

class Triangle: public Object3D {

public:
	Triangle(Vec3f& a, Vec3f& b, Vec3f& c, Material* material);
	bool intersect(const Ray &r, Hit &h, float tmin);

private:
	Vec3f _a,_b,_c;

};




#endif