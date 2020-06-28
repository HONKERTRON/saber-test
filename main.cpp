#include "main.h"

int main(int arc, char** argv)
{
	// ѕроверка дл€ первого задани€ дл€ длинного способа
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
	
	// ѕроверка первого задани€ дл€ короткого способа
	for (int i = -130; i < 130; ++i)
	{
		dec2bin(i);
	}
	*/

	// ѕроверка дл€ второго задани€
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

	return 0;
}