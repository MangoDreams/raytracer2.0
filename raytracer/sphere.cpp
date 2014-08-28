#include "sphere.h"


Sphere::Sphere(Vec3f &center, float radius, Material* material){
	_radius = radius;
	_center = center;
	_material = material;

}
bool Sphere::intersect(const Ray &r, Hit &h, float tmin){

	/*Vector equation for sphere
	P*P - r^2 = 0
	((R0-c) + td)*((R0-c) + td) - r^2 = 0
	(td)^2 + 2R0-c)td + (R0-c)^2 - r^2 =0
	Use quadratic equation solve for t
	a = (d^2)
	b = 2(R0-c)d
    c = ((R0-c)^2 - r^2)
	*/

	Vec3f rayOrigin, rayDirection,segment,Q;
	float tpos,tneg,a,b,c,discriminant;

	rayOrigin = r.getOrigin();
	rayDirection = r.getDirection();
	segment = rayOrigin - _center;

	a = rayDirection.Dot3(rayDirection);
	b = 2*segment.Dot3(rayDirection);
	c = segment.Dot3(segment) - _radius*_radius;

	discriminant = sqrt(b*b - 4*a*c); 

	tpos = (-b + discriminant)/(2*a);
	tneg = (-b - discriminant)/(2*a);

	if (tneg > tmin && tneg < h.getT()){
			Q = r.pointAtParameter(tneg);
			Q = Q - _center;
			Q.Normalize();
			h.set(tneg, _material,Q,r);
			return true;
		}
	else if (tpos > tmin && tpos < h.getT()){
			Q = r.pointAtParameter(tpos);
			Q = Q - _center;
			Q.Normalize();
			h.set(tpos,_material,Q,r);
			return true;
		}
	return false;

}