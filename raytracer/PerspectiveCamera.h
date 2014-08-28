#ifndef _PerspectiveCamera_H_
#define _PerspectiveCamera_H_

#include "camera.h"

class PerspectiveCamera : public Camera {

public:
	PerspectiveCamera(Vec3f &center, Vec3f &direction, Vec3f &up, float angle);
	PerspectiveCamera::~PerspectiveCamera();
	virtual Ray generateRay(Vec2f point);

private:
	Matrix* _viewMatrix;
	Vec3f _center;
	float _z;

};


#endif