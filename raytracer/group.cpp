#include "group.h"

Group::Group(int numObjects){
	_sceneObjects =  new Object3D*[numObjects];
	_size = numObjects;
}

Group::~Group(){
	delete[] _sceneObjects;
}


bool Group::intersect(const Ray &r, Hit &h, float tmin){
	
	for (int i = 0; i < _size; i++){
		_sceneObjects[i]->intersect(r,h,tmin);
	}

	return (h.getT() != TMAX);
}

bool Group::intersectShadowRay(const Ray &r, Hit &h, float tmin){
	
	bool ret;
	for (int i = 0; i < _size; i++){
		ret = _sceneObjects[i]->intersectShadowRay(r,h,tmin);
		if(ret) return true;
	}

	return false;
}

void Group::addObject(int idx, Object3D* obj){
	_sceneObjects[idx] = obj;
}