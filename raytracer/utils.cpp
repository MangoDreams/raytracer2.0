#include "utils.h"

bool transmittedDirection(const Vec3f &normal, Vec3f &incoming,float index_i, float &index_t, Vec3f &transmitted){
	float nr, cosI,cosT,sinT2;
	Vec3f n = normal;

	incoming.Normalize();
	if(normal.Dot3(incoming) > 0){
		n = -1.0*normal;
		index_t = 1;
	}

	incoming = -1.0*incoming;
	nr = index_i/index_t;
	cosI = n.Dot3(incoming);

	sinT2 = nr*nr*(1 - cosI*cosI);
	
	if(sinT2 < 1.0){
		cosT = sqrt(1-sinT2);
		transmitted = (nr*cosI - cosT)*n - nr*incoming;
		transmitted.Normalize();
		return true;
	}

	/*total internal refraction*/
	return false;	
}

Vec3f mirrorDirection(const Vec3f &normal, const Vec3f &incoming){
	Vec3f reflectedRay = incoming - 2*(incoming.Dot3(normal))*normal;
	reflectedRay.Normalize();
	return reflectedRay;
}

void turnPositive(Vec3f &v){
	if(v.r() < 0) v.Set(-v.r(),v.g(),v.b());
	if(v.g() < 0) v.Set(v.r(),-v.g(),v.b());
	if(v.b() < 0) v.Set(v.r(),v.g(),-v.b());
}

float screenSpace(int current_pixel,int num_pixels){
	return 2*(current_pixel/(float)num_pixels) - 1;
	}
