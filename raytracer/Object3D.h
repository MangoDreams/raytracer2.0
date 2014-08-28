#ifndef _OBJECT3D_H
#define _OBJECT3D_H

#include "Material.h"
#include "matrix.h"

class Object3D{

public:
	Object3D(){};
	~Object3D(){};

	virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;
	virtual bool intersectShadowRay(const Ray &r, Hit &h, float tmin){return intersect(r, h, tmin);}
	
	Material* _material;
};


#endif