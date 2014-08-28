#define WIDTH 400
#define HEIGHT 400

#include "RayTracer.h"
#include "image.h"

void generateImage(const char* scene, int bounces, int renderMode){
	
	float x,y;
	Vec2f point;
	Vec3f color;
	
	Image img(WIDTH,HEIGHT);
	
	SceneParser* s = new SceneParser(scene);
	RayTracer myTracer(s,bounces,(float).001,renderMode);

	for(int i = 0; i < img.Width(); i++){

		x = screenSpace(i,img.Width());
		
		for(int j = 0; j < img.Height(); j++){	

			y = screenSpace(j, img.Height());
			
			point.Set(x,y); 
			color = myTracer.render(point);
			img.SetPixel(i,j,color);
		}
	}
	
	std::string imgName(scene,0,strlen(scene)-4);
	imgName.append(".bmp");

	std::cout << "Done raytracing " << imgName.c_str() << std::endl;
	img.SaveBMP(imgName.c_str());
}


int main(void){

	generateImage("scene4_reflective_sphere.txt",3,0);
	generateImage("scene9_point_light_distance.txt",0,0);

	/*warning: some images take up to 40 mins to render

	generateImage("scene1_exponent_variations.txt",0,0);
	generateImage("scene2_plane_sphere.txt",0,0);
	generateImage("scene3_colored_lights.txt",0,0);

	generateImage("scene4_reflective_sphere.txt",0,0);
	generateImage("scene4_reflective_sphere.txt",1,0);
	generateImage("scene4_reflective_sphere.txt",2,0);
	generateImage("scene4_reflective_sphere.txt",3,0);

	generateImage("scene5_transparent_bars.txt",0,0);
	generateImage("scene5_transparent_bars.txt",1,0);
	generateImage("scene5_transparent_bars.txt",2,0);
	generateImage("scene5_transparent_bars.txt",3,0);
	
	generateImage("scene6_transparent_sphere_1.0.txt",5,0);
	generateImage("scene7_transparent_sphere_1.1.txt",5,0);
	generateImage("scene8_transparent_sphere_2.0.txt",5,0);

	generateImage("scene9_point_light_distance.txt",0,0);
	generateImage("scene10_point_light_circle.txt",0,0);
	
	generateImage("scene13_bunny.txt",0,2);*/

	getchar();
}
