#include "task1.h"

bool dec2bin(int number, unsigned int len, char* res) // Отрицательные числа преобразуются в дополнительный код
/*
	number - входное число
	len - количество разрядов, выделенных для записи числа в двоичном виде
	result - указатель на строку с результатом
*/
{
	bool success = true;

	for (int i = 0; i < len; ++i)
		res[i] = '0';
	res[len] = '\0';

	int base = 2;
	int i = len-1;
	int sign = 1;

	if (number < 0)
	{
		number = -number;
		sign = -1;
	}

	while (success && number > 0)
	{
		res[i] = '0' + (number % base);
		number /= base;
		i--;
		if (i < 0)
			success = false;
	}

	if (sign == -1)
	{
		for (int i = 0; i < len; ++i)
			res[i] == '0' ? res[i] = '1' : res[i] = '0';
		unsigned int overflow = 1;
		for (int i = len - 1; i >= 0; --i)
		{
			if (overflow)
			{
				if (res[i] == '1')
				{
					res[i] = '0';
				}
				else
				{
					overflow = 0;
					res[i] = '1';
				}
			}
		}
		if (overflow)
			return false;
	}

	return success;
}