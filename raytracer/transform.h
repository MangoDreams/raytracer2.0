#include "Object3D.h"

class Transform : public Object3D {
	public:
		Transform(Matrix &m, Object3D* o);
		~Transform();
		bool intersect(const Ray &r, Hit &h, float tmin);

	private:
		Object3D* _obj;
		Matrix* _m, *_mTranspose;
};