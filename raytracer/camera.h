#ifndef _CAMERA_H
#define _CAMERA_H

#include "matrix.h"
#include "ray.h"

class Camera {

public:

	Camera(){};
	~Camera(){};

	virtual Ray generateRay(Vec2f point) = 0;
};

#endif