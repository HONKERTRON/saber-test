#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>

//2. Реализуйте функции сериализации и десериализации двусвязного списка в бинарном формате в файл.

const char delimiter = '\n';
#pragma pack(push, 1)
struct LiLiHeader
{
	char FileSignature[4];
	int Count;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct LiLiRecord
{
    int RandPtr;
    unsigned int DataSize;
};
#pragma pack(pop)

struct ListNode 
{
    ListNode* prev;
    ListNode* next;
    ListNode* rand; // указатель на произвольный элемент данного списка либо NULL
    std::string data;

	//Поскольку реализация самого линейного списка в задание не входит, она отмечена отдельно
    ListNode();
};

class List 
{
public:
    void Serialize(FILE* file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
    void Deserialize(FILE* file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
	
	//Плейсхолдеры методов для проверки работоспособности
    List();
    ~List();
    void PushBack(std::string data);
    void AddRelation(int i, int j);
    void Print();

private:
    ListNode* head;
    ListNode* tail;
    int       count;
};
