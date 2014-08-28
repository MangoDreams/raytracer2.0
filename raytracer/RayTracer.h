#ifndef _RAY_TRACER_H
#define _RAY_TRACER_H

#include "scene_parser.h"
#include "hit.h"
#include "utils.h"

class RayTracer {
	public:
		RayTracer(SceneParser *s, int maxBounces, float minWeight, int renderMode);
		~RayTracer(){delete _s;}
				Vec3f render(Vec2f point);		Vec3f traceRay(Ray &ray, Hit &hit, float tmin, int bounces, float weight, float indexOfRefraction) const;
		Vec3f traceDepth(Ray &ray, Hit &hit, float tmin);
		Vec3f traceNormal(Ray &ray, Hit &hit, float tmin);


	private:
		Group* _grp;
		Vec3f _ambientColor,_background;
		SceneParser* _s;
		Camera* _camera;
		int _maxBounces,_renderMode;
		float _minWeight;
};


#endif