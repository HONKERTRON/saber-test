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

void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces)
{
	std::vector<vec3> normals_faces(nfaces / 3);
	std::vector<std::vector<int>> incidence(nverts);

	for (int i = 0; i < nfaces / 3; ++i)
	{
		incidence[faces[i*3]].push_back(i);
		incidence[faces[i*3 + 1]].push_back(i);
		incidence[faces[i*3 + 2]].push_back(i);

		vec3 v1;
		vec3 v2;
		v1.copy(verts[faces[i * 3 + 1]]);
		v2.copy(verts[faces[i * 3 + 2]]);
		v1.sub(verts[faces[i * 3]]);
		v1.normalize();
		v2.sub(verts[faces[i * 3]]);
		v2.normalize();
		vec3 normal;
		normal.cross(v1, v2);
		normal.normalize();
		//В случае, если уравновешивать нормали придется другим способом, пригодится эта формула
		//float sin_alpha = normal.length() / (v1.length() * v2.length());
		//normal.dot(asinf(sin_alpha));
		float S = area(verts[faces[i * 3]], verts[faces[i * 3 + 1]], verts[faces[i * 3 + 2]]);
		normal.dot(S);
		normals_faces[i] = normal;
	}
	for (int i = 0; i < nverts; ++i)
	{
		vec3 normal;
		for (int j = 0; j < incidence[i].size(); ++j)
		{
			normal.add(normals_faces[incidence[i][j]]);
		}
		normal.normalize();
		normals[i] = normal;
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

void vec3::dot(float a)
{
	for (int i = 0; i < 3; ++i)
		pos[i] *= a;
}
