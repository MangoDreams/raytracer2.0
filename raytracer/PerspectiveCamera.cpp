#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(Vec3f &center, Vec3f &direction, Vec3f &up, float angle){
	
	Matrix translationMatrix;
	Vec3f u,v,w;

	_center = center;
	_z = 1/(tan(angle/2));


	w = direction;
	w.Normalize();

	Vec3f::Cross3(u,up,direction);
	u.Normalize();

	Vec3f::Cross3(v,w,u);
	_viewMatrix = new Matrix();

	_viewMatrix->Set(0,0,u.x());
	_viewMatrix->Set(1,0,u.y());
	_viewMatrix->Set(2,0,u.z());

	_viewMatrix->Set(0,1,v.x());
	_viewMatrix->Set(1,1,v.y());
	_viewMatrix->Set(2,1,v.z());
	
	_viewMatrix->Set(0,2,w.x());
	_viewMatrix->Set(1,2,w.y());
	_viewMatrix->Set(2,2,w.z());

	_viewMatrix->Set(3,3,1);
	
	translationMatrix.Set(0,0,1);
	translationMatrix.Set(1,1,1);
	translationMatrix.Set(2,2,1);
	translationMatrix.Set(3,3,1);
	translationMatrix.Set(3,0,-center.x());
	translationMatrix.Set(3,1,-center.y());
	translationMatrix.Set(3,2,-center.z());
	
	(*_viewMatrix) = (*_viewMatrix)*translationMatrix;
	_viewMatrix->Inverse();
}

PerspectiveCamera::~PerspectiveCamera(){
	delete _viewMatrix;
}


Ray PerspectiveCamera::generateRay(Vec2f point){
	Vec3f point3D, dir;

	point3D.Set(point.x(),point.y(),_z);
	_viewMatrix->Transform(point3D);

	dir = (point3D - _center);
	dir.Normalize();

	Ray r(dir, _center);
	return r;
}
