#include "main.h"

int main(int arc, char** argv)
{
	// Проверка для первого задания для длинного способа
	/*unsigned int size = 8;
	char* str = new char[size+1];
	int num;

	for (int i = -130; i < 130; ++i)
	{
		num = rand() % 256 - 200;
		num = i;
		if (dec2bin(num, size, &str[0]))
		{
			std::cout << num << "\t:\t" << str << "\r\n";
		}
		else
			std::cout << "Error on number " << num << "\n";
	}
	
	delete[] str;
	
	// Проверка первого задания для короткого способа
	for (int i = -130; i < 130; ++i)
	{
		dec2bin(i);
	}
	*/

	// Проверка для второго задания
	//FILE* f;
	//fopen_s(&f, "./test.bin", "wb");

	//List list;

	//int size = 10;
	//for (int i = 0; i < size; ++i)
	//{
	//	std::string str;
	//	int len = rand() % size;
	//	for (int j = 0; j < len; ++j)
	//		str += 'a' + rand() % size;
	//	list.PushBack(str);
	//}
	//for (int i = 0; i < size; ++i)
	//{
	//	if ((rand() % 100) > 50)
	//	{
	//		int index = rand() % size;
	//		if (index == i)
	//			index = 0;
	//		list.AddRelation(i, index);
	//	}
	//}
	//
	//list.Print();
	//list.Serialize(f);

	//fclose(f);

	//std::cout << "-------------------\n\n";

	//fopen_s(&f, "./test.bin", "rb");

	//List list_ceck;

	//list_ceck.Deserialize(f);
	//list_ceck.Print();

	//fclose(f);

	// Проверка 3 задачи с квадратом
	//vec3 verts[4];
	//verts[0] = vec3(1.0f, 1.0f, 0.0f);
	//verts[1] = vec3(1.0f, -1.0f, 0.0f);
	//verts[2] = vec3(-1.0f, -1.0f, 0.0f);
	//verts[3] = vec3(-1.0f, 1.0f, 0.0f);
	//int nverts = 4;

	//vec3 normals[4];

	//int faces[] = {2, 1, 0, 0, 3, 2};

	//int nfaces = 6;

	// Проверка 3 задачи с кубом
	//vec3 verts[8];
	//verts[0] = vec3(1.0f, 1.0f, -1.0f);
	//verts[1] = vec3(1.0f, -1.0f, -1.0f);
	//verts[2] = vec3(1.0f, 1.0f, 1.0f);
	//verts[3] = vec3(1.0f, -1.0f, 1.0f);
	//verts[4] = vec3(-1.0f, 1.0f, -1.0f);
	//verts[5] = vec3(-1.0f, -1.0f, -1.0f);
	//verts[6] = vec3(-1.0f, 1.0f, 1.0f);
	//verts[7] = vec3(-1.0f, -1.0f, 1.0f);
	//
	//int nverts = 8;

	//vec3 normals[8];

	//int faces[] = { 5, 3, 1, 3, 8, 4, 7, 6, 8, 2, 8, 6, 1, 4, 2, 5, 2, 6, 5, 7, 3, 3, 7, 8, 7, 5, 6, 2, 4, 8, 1, 3, 4, 5, 1, 2 };
	//int nfaces = 36;
	//for (int i = 0; i < nfaces; ++i)
	//	faces[i]--;

	// Запуск проверки

	//calc_mesh_normals(normals, verts, faces, nverts, nfaces);

	//for (int i = 0; i < nverts; ++i)
	//{
	//	std::cout.precision(4);
	//	std::cout << normals[i].pos[0] << "  " << normals[i].pos[1] << "  " << normals[i].pos[2] << "\n";
	//}

	return 0;
}