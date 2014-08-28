#include "transform.h"

Transform::Transform(Matrix &m, Object3D* o){

	_obj = o;
	_m = new Matrix(m);
	_m->Inverse();
	_mTranspose = new Matrix(*_m);
	_mTranspose->Transpose();	
}

/* For derivation:
		groups.csail.mit.edu/graphics/classes/6.837/F04/lectures/04_TransformationsAndPhong.pdf 
*/
Transform::~Transform(){
	delete _m;
	delete _mTranspose;
}

bool Transform::intersect(const Ray &r, Hit &h, float tmin){
	
	bool ret;
	float oldT;
	Vec3f originOS, directionOS,normalWS;

	oldT = h.getT();
	directionOS = r.getDirection();
	originOS = r.getOrigin();

	_m->Transform(originOS);
	_m->TransformDirection(directionOS);

	Ray newRay(directionOS,originOS);

	ret = _obj->intersect(newRay,h,tmin);

	normalWS = h.getNormal();
	_mTranspose->Transform(normalWS);

	normalWS.Normalize();
	if(h.getT() < oldT){ 
		h.set(h.getT(),h.getMaterial(),normalWS,r);	
	}
	
	return ret;
}