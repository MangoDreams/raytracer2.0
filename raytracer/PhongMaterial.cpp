#include "PhongMaterial.h"

PhongMaterial::PhongMaterial(const Vec3f &diffuseColor, const Vec3f &specularColor, 
							float exponent,const Vec3f &transparentColor, 
							 const Vec3f &reflectiveColor,float indexOfRefraction){
		
			_diffuseColor = diffuseColor;
			_specularColor = specularColor;
			_exponent = exponent;
			_reflectiveColor = reflectiveColor;
			_transparentColor = transparentColor;
			_indexOfRefraction = indexOfRefraction;
}



Vec3f PhongMaterial::Shade(const Ray &ray, const Hit &hit, 
					const Vec3f &dirToLight, const Vec3f &lightColor)const{

		/* For derivation:
		groups.csail.mit.edu/graphics/classes/6.837/F04/lectures/04_TransformationsAndPhong.pdf 
		*/

		Vec3f n,l,v,r;
		float nl;

		l = dirToLight;
		n = hit.getNormal();
		v = -1.0*(hit.getIntersectionPoint() - ray.getOrigin());
		
		l.Normalize();
		n.Normalize();
		v.Normalize();

		nl = n.maxDot3(l);
		r = (2*nl*n)-l;
		r.Normalize();

		return (_diffuseColor*nl + _specularColor*powf(v.maxDot3(r),_exponent))*lightColor;
}