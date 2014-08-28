#ifndef _ORTHOGRAPHIC_CAMERA_H
#define _ORTHOGRAPHIC_CAMERA_H

#include "Camera.h"

class OrthographicCamera: public Camera {

public:
	OrthographicCamera(Vec3f &center, Vec3f &direction, Vec3f &up, float imgSize);
	~OrthographicCamera();

	Ray generateRay(Vec2f point);

private:

	float _imgSize;
	Matrix *_viewMatrix;
	Vec3f _direction;
	
};

#endif