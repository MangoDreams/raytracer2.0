#ifndef _PHONG_MATERIAL_H
#define _PHONG_MATERIAL_H

#include "Material.h"

class PhongMaterial : public Material{
	public:
		PhongMaterial(const Vec3f &diffuseColor, const Vec3f &specularColor, 
					 float exponent,const Vec3f &transparentColor, 
					 const Vec3f &reflectiveColor,float indexOfRefraction);
		
		~PhongMaterial();

		Vec3f Shade(const Ray &ray, const Hit &hit, const Vec3f &dirToLight, const Vec3f &lightColor) const;
		
		Vec3f getDiffuse(){return _diffuseColor;}
		Vec3f getReflective(){return _reflectiveColor;}
		Vec3f getTransmittance(){return _transparentColor;}
		float getIOR(){return _indexOfRefraction;}

		bool isReflective(){return (_reflectiveColor.Length() > 0.0);}
		bool isTransparent(){return (_transparentColor.Length() > 0.0);}


	private:
		Vec3f _diffuseColor,_transparentColor,_reflectiveColor,_specularColor;
		float _exponent,_indexOfRefraction;

};

#endif