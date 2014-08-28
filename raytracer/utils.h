#ifndef _UTILS_H
#define _UTILS_H

#include "vectors.h"

bool transmittedDirection(const Vec3f &normal, Vec3f &incoming,float index_i, float &index_t, Vec3f &transmitted);

Vec3f mirrorDirection(const Vec3f &normal, const Vec3f &incoming);

void turnPositive(Vec3f &v);

float screenSpace(int current_pixel,int num_pixels);

#endif