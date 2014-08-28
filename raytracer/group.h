#ifndef _GROUP_H
#define _GROUP_H

#include "Object3D.h"

class Group: public Object3D{

public:
	Group(int numObjects);
	~Group();
	
	virtual bool intersect(const Ray &r, Hit &h, float tmin);
	
	bool intersectShadowRay(const Ray &r, Hit &h, float tmin);
	void addObject(int idx, Object3D* obj);
	

private:
	Object3D** _sceneObjects;
	int _size;                
};

#endif
