#pragma once
#include <math.h>
#include <vector>

// 3. Реализуйте функцию расчета усредненных нормалей для вершин меша, заданного индексированными треугольниками.

struct vec3
{
	float pos[3];

	vec3();
	vec3(float x, float y, float z);
	float length();
	void normalize();
	// Можно было сделать операторы, но все равно есть библиотеки, которые реализуют все это
	void add(vec3 vec);
	void sub(vec3 vec);
	void cross(vec3 vec1, vec3 vec2);
	void copy(vec3 vec);
	void dot(float a);
};

void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces);

