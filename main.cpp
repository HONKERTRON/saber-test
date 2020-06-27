#include "main.h"

int main(int arc, char** argv)
{
	unsigned int size = 8;
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
	return 0;
}