#pragma once

#include <vector>
#include <string>
#include <iostream>

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
};
#pragma pack(pop)

struct ListNode 
{
    ListNode* prev;
    ListNode* next;
    ListNode* rand; // ��������� �� ������������ ������� ������� ������ ���� NULL
    std::string data;

    //ListNode();
};

class List 
{
public:
    //List();
    //~List();
    //void PushBack(std::string data);
    //void AddRelation(int i, int j);
    //void Print();

    void Serialize(FILE* file);  // ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
    void Deserialize(FILE* file);  // �������� �� ����� (���� ������ � ������� fopen(path, "rb"))

private:
    ListNode* head;
    ListNode* tail;
    int       count;
};
