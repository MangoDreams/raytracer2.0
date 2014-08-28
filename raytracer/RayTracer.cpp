#include "RayTracer.h"

RayTracer::RayTracer(SceneParser* s, int maxBounces, float minWeight,int renderMode){

	_s = s;
	_maxBounces = maxBounces;
	_minWeight = minWeight;
	_renderMode = renderMode;

	_grp = s->getGroup();
	_camera = s->getCamera();
	_ambientColor = s->getAmbientLight();
	_background = s->getBackgroundColor();

}

Vec3f RayTracer::render(Vec2f point){
	Ray r;
	Hit h;

	r = _camera->generateRay(point);
	h.set(TMAX,0,Vec3f (0,0,0),r);

	/*Magic numbers*/
	if(_renderMode == 1) return traceDepth(r,h,TMIN);
	if(_renderMode == 2) return traceNormal(r,h, TMIN);
	
	return traceRay(r,h, TMIN,0,1,1);
}

Vec3f RayTracer::traceRay(Ray &ray, Hit &hit, float tmin, int bounces, float weight, float indexOfRefraction) const{
	float lightDistance,shadowDistance,kt,kr;	bool createsShadow;	Vec3f color,lightDir, lightColor, hitPoint;	Light* light;	color = _background;

	if (_grp->intersect(ray,hit,tmin)){
		
		color = hit.getMaterial()->getDiffuse()*_ambientColor;
		hitPoint = hit.getIntersectionPoint();

		for(int i = 0; i < _s->getNumLights(); i++){		
			light = _s->getLight(i);
			light->getIllumination(hitPoint, lightDir, lightColor,lightDistance);			Ray shadowRay(lightDir,hitPoint);			Hit shadowHit;			createsShadow = _grp->intersectShadowRay(shadowRay,shadowHit,tmin);			shadowDistance = (shadowHit.getIntersectionPoint() - hitPoint).Length();						if(!createsShadow || lightDistance < shadowDistance){						color += hit.getMaterial()->Shade(ray,hit,lightDir,lightColor);				}		}		if(bounces == _maxBounces ||  weight < _minWeight){			return color;		}				if(hit.getMaterial()->isReflective()){			kr = hit.getMaterial()->getReflective().Length()*weight;			Vec3f mirrorDir = mirrorDirection(hit.getNormal(), ray.getDirection());			Ray mirrorRay(mirrorDir, hitPoint);			Hit mirrorHit;			color += hit.getMaterial()->getReflective()*traceRay(mirrorRay,mirrorHit,tmin,bounces+1,kr,indexOfRefraction);		}				if(hit.getMaterial()->isTransparent()){			Vec3f transmittedDir,incoming;			float nt;			incoming = ray.getDirection();			nt = hit.getMaterial()->getIOR();						if(transmittedDirection(hit.getNormal(),incoming,indexOfRefraction,nt,transmittedDir)){				kt = hit.getMaterial()->getTransmittance().Length()*weight;				Ray transmittedRay(transmittedDir,hitPoint);				Hit refractiveHit;				color += hit.getMaterial()->getTransmittance()*traceRay(transmittedRay,refractiveHit,tmin,bounces+1,kt,nt);							}		}	}
	return color;
}

Vec3f RayTracer::traceDepth(Ray &ray, Hit &hit, float tmin){
	/*for debugging depth*/

	float t,c;
	Vec3f color(0,0,0);
	float min = 13;
	float max = 16;

	_grp->intersect(ray,hit,tmin);
	t = hit.getT();

	if(t >= min && t <= max){
		c = 1.0 - ((t - min)/(max - min));
		color.Set(c,c,c);
	}

	return color;
}

Vec3f RayTracer::traceNormal(Ray &ray, Hit &hit, float tmin){

	Vec3f n;
	_grp->intersect(ray,hit,tmin);

	if(hit.getNormal().x() == 0 && hit.getNormal().y() == 0 && hit.getNormal().x() == 0) n.Set(0,0,0);

	else {
		n = hit.getNormal();
		turnPositive(n);
	}

	return n;
}