#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "hit.h"

class Material {
	public:
		Material(const Vec3f &diffuseColor, const Vec3f &transparentColor, const Vec3f &reflectiveColor, float indexOfRefraction);
		Material(){};
		~Material(){};				virtual Vec3f Shade(const Ray &ray, const Hit &hit, const Vec3f &dirToLight, const Vec3f &lightColor) const = 0;	
		
		//very hacky
		
		virtual Vec3f getDiffuse() = 0; 
		virtual Vec3f getReflective() = 0;
		virtual Vec3f getTransmittance() = 0;
		virtual float getIOR() = 0;

		virtual bool isTransparent() = 0;
		virtual bool isReflective() = 0;
};

#endif