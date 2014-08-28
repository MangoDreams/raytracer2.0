#include "triangle.h"

Triangle::Triangle(Vec3f &a, Vec3f &b, Vec3f &c, Material* material){
	_a = a;
	_b = b;
	_c = c;
	_material = material;
}



bool Triangle::intersect(const Ray& r, Hit& h, float tmin){

	/* For derivation of Barycentric approach:
	groups.csail.mit.edu/graphics/classes/6.837/F03/lectures/02_rayCast2.pdf
	*/

	float D,beta, gamma,alpha, t;

	Vec3f rayOrigin, rayDirection,Na,Nb,Nc,Nq;

	rayOrigin = r.getOrigin();
	rayDirection = r.getDirection();

	D = det3x3(_a.x() - _b.x(),_a.y() - _b.y(),_a.z() - _b.z(),_a.x() - _c.x(),_a.y() - _c.y(),_a.z() - _c.z(),rayDirection.x(),rayDirection.y(),rayDirection.z());

	beta = det3x3(_a.x() - rayOrigin.x(),_a.y() - rayOrigin.y(),_a.z() - rayOrigin.z(),_a.x() - _c.x(),_a.y() - _c.y(),_a.z() - _c.z(),rayDirection.x(),rayDirection.y(),rayDirection.z());
	beta = beta/D;

	gamma = det3x3(_a.x() - _b.x(),_a.y() - _b.y(),_a.z() - _b.z(),_a.x() - rayOrigin.x(),_a.y() - rayOrigin.y(),_a.z() - rayOrigin.z(), rayDirection.x(),rayDirection.y(),rayDirection.z());
	gamma = gamma/D;

	t = det3x3(_a.x() - _b.x(),_a.y() - _b.y(),_a.z() - _b.z(),_a.x() - _c.x(),_a.y() - _c.y(),_a.z() - _c.z(), _a.x() - rayOrigin.x(),_a.y() - rayOrigin.y(),_a.z() - rayOrigin.z());
	t = t/D;

	if (t > tmin && t < h.getT()){
		
		if (beta + gamma < 1 && beta > 0 && gamma > 0){
			alpha = 1 - beta - gamma;
			Vec3f::Cross3(Na, (_b-_a),(_c - _a));
			Vec3f::Cross3(Nb, (_c-_b),(_a - _b));
			Vec3f::Cross3(Nc, (_a-_c),(_b - _c));
			Na.Normalize();
			Nb.Normalize();
			Nc.Normalize();
			
			Na = alpha*Na;
			Nb = beta*Nb;
			Nc = gamma*Nc;

			Nq = Na + Nb + Nc;
			Nq.Normalize();
			
			h.set(t, _material,Nq,r);
			return true;

		}
	}

	return false;
}