#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(Vec3f &center, Vec3f &direction, Vec3f &up, float imgSize){		
	
	Matrix translationMatrix;
	Vec3f u,v,w;
	_imgSize = imgSize; 
	
	w = direction;
	w.Normalize();
	_direction = w;

	Vec3f::Cross3(u,up,direction);
	u.Normalize();

	Vec3f::Cross3(v,w,u);
	_viewMatrix = new Matrix();

	/*Change of orthronormal basis*/
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
	

	*(_viewMatrix) = (*_viewMatrix)*translationMatrix;
	_viewMatrix->Inverse();

}

OrthographicCamera::~OrthographicCamera(){
	delete _viewMatrix;
}

Ray OrthographicCamera::generateRay(Vec2f point){

	point.Scale(_imgSize/2,_imgSize/2);
	Vec3f point3D(point.x(),point.y(),0);
	
	_viewMatrix->Transform(point3D);

	Ray r(_direction, point3D);

	return r;
}