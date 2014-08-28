#include "plane.h"

Plane::Plane(Vec3f& normal, float d, Material* material){
	_normal = normal;
	_d = d;
	_material = material;
}

bool Plane::intersect(const Ray& r, Hit& h, float tmin){
	
	/*
	normal*Point on plane = d 
	normal*(tl + t0) = d (at intersection)
	tl*normal + t0*normal = d
	t = (d - normal*t0)/(l*normal)
	*/

	Vec3f rayOrigin, rayDirection;
	float numerator, denominator,t;
	t = 0;

	rayOrigin = r.getOrigin();
	rayDirection = r.getDirection();

	numerator = _d - _normal.Dot3(rayOrigin);
	denominator = _normal.Dot3(rayDirection);


	if(numerator != 0 && denominator != 0){
		t = numerator/denominator;
		if (t > tmin && t < h.getT()){
			h.set(t, _material,_normal,r);
			return true;
			}
		}
	return false;
}
