#include "task3.h"

float area(vec3 a, vec3 b, vec3 c)
{
	vec3 ab;
	ab.copy(a);
	ab.sub(b);
	float ab_l = ab.length();
	vec3 bc;
	bc.copy(b);
	bc.sub(c);
	float bc_l = bc.length();
	vec3 ca;
	ca.copy(c);
	ca.sub(a);
	float ca_l = ca.length();
	float P = (ab_l + bc_l + ca_l) / 2.0f;
	float S = sqrtf((P - ab_l) * (P - bc_l) * (P - ca_l) * P);
	return S;
}

float angle(vec3 a, vec3 b)
{
	return acosf(a.dot(b) / (a.length() * b.length()));
}

void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces)
{
	for (int i = 0; i < nfaces / 3; ++i)
	{
		vec3 p1 = verts[faces[i * 3]];
		vec3 p2 = verts[faces[i * 3 + 1]];
		vec3 p3 = verts[faces[i * 3 + 2]];

		vec3 v1;
		vec3 v2;
		v1.copy(p2);
		v2.copy(p3);
		v1.sub(p1);
		v1.normalize();
		v2.sub(p1);
		v2.normalize();
		vec3 n;
		n.cross(v1, v2);
		n.normalize();

		float a1 = angle(v1, v2);
		v1.copy(p1);
		v2.copy(p3);
		v1.sub(p2);
		v1.normalize();
		v2.sub(p2);
		v2.normalize();
		float a2 = angle(v1, v2);
		v1.copy(p1);
		v2.copy(p2);
		v1.sub(p3);
		v1.normalize();
		v2.sub(p3);
		v2.normalize();
		float a3 = angle(v1, v2);

		//n.dot(a1);
		normals[faces[i * 3]].add(n.dot(a1));
		normals[faces[i * 3 + 1]].add(n.dot(a2));
		normals[faces[i * 3 + 2]].add(n.dot(a3));
	}
	for (int i = 0; i < nverts; ++i)
	{
		normals[i].normalize();
	}
}

vec3::vec3()
{
	for (int i = 0; i < 3; ++i)
		pos[i] = 0.0f;
}

vec3::vec3(float x, float y, float z)
{
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}

float vec3::length()
{
	return sqrtf(pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2]);
}

void vec3::normalize()
{
	float len = length();
	pos[0] /= len;
	pos[1] /= len;
	pos[2] /= len;

}

void vec3::add(vec3 vec)
{
	for (int i = 0; i < 3; ++i)
		pos[i] += vec.pos[i];
}

void vec3::sub(vec3 vec)
{
	for (int i = 0; i < 3; ++i)
		pos[i] -= vec.pos[i];
}

void vec3::cross(vec3 vec1, vec3 vec2)
{
	pos[0] = vec1.pos[1] * vec2.pos[2] - vec1.pos[2] * vec2.pos[1];
	pos[1] = vec1.pos[0] * vec2.pos[2] - vec1.pos[2] * vec2.pos[0];
	pos[2] = vec1.pos[0] * vec2.pos[1] - vec1.pos[1] * vec2.pos[0];
}

void vec3::copy(vec3 vec)
{
	for (int i = 0; i < 3; ++i)
		pos[i] = vec.pos[i];
}

vec3 vec3::dot(float a)
{
	vec3 res;
	res.copy(*this);
	for (int i = 0; i < 3; ++i)
		res.pos[i] *= a;
	return res;
}

float vec3::dot(vec3 a)
{
	return (pos[0] * a.pos[0]) + (pos[1] * a.pos[1]) + (pos[2] * a.pos[2]);
}
