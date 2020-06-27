#include "task2.h"

void List::Serialize(FILE* file)
{
	if (count > 0)
	{
		LiLiHeader header;
		header.FileSignature[0] = 'h';
		header.FileSignature[1] = 'L';
		header.FileSignature[2] = 'i';
		header.FileSignature[3] = 'L';
		header.Count = count;

		fwrite(&header, sizeof(header), 1, file);

		ListNode* cur = head;
		int k = 0;
		while (cur != tail->next)
		{
			LiLiRecord r;
			if (cur->rand)
			{
				int j = 1;
				ListNode* tmp = head;
				while (tmp != cur->rand)
				{
					tmp = tmp->next;
					j++;
				}
				r.RandPtr = j;
			}
			else
				r.RandPtr = 0;
			r.DataLength = cur->data.size();
			fwrite(&r, sizeof(r), 1, file);
			for (int i = 0; i < r.DataLength; ++i)
			{
				fwrite(&cur->data[i], sizeof(cur->data[i]), 1, file);
			}
			cur = cur->next;
			k++;
		}
	}
}

void List::Deserialize(FILE* file)
{
	LiLiHeader header;
	fread(&header, sizeof(header), 1, file);

	std::vector<LiLiRecord*> records;
	std::vector<ListNode*> nodes;
	std::string data;
	char c;
	
	for (int i = 0; i < header.Count; ++i)
	{
		data.clear();
		records.push_back(new LiLiRecord());
		fread(records[i], sizeof(LiLiRecord), 1, file);
		for (int j = 0; j < records[i]->DataLength; ++j)
		{
			fread(&c, sizeof(c), 1, file);
			data += c;
		}
		nodes.push_back(new ListNode());
		nodes[i]->data = data;
	}

	head = nodes[0];
	tail = nodes[nodes.size() - 1];
	for (int i = 0; i < header.Count; ++i)
	{
		int index = records[i]->RandPtr;
		if(index > 0)
			nodes[i]->rand = nodes[index - 1];
		if (i > 0)
			nodes[i]->prev = nodes[i - 1];
		if (i < header.Count - 1)
			nodes[i]->next = nodes[i + 1];
	}

	for (auto& r : records)
		delete r;
}

// Плейсхолдеры для проверки
//List::List()
//{
//	head = nullptr;
//	tail = nullptr;
//	count = 0;
//}
//
//List::~List()
//{
//	ListNode* cur = head;
//	ListNode* tmp = nullptr;
//	if (cur)
//	{
//		while (cur != tail)
//		{
//			if(cur->prev)
//				delete cur->prev;
//			cur = cur->next;
//			
//		}
//		delete cur;
//	}
//}
//
//void List::PushBack(std::string data)
//{
//	ListNode* node = new ListNode();
//	node->data = data;
//	if (head)
//	{
//		tail->next = node;
//		node->prev = tail;
//		tail = node;
//		node->next = nullptr;
//	}
//	else
//	{
//		head = node;
//		tail = head;
//	}
//	count++;
//}
//
//void List::AddRelation(int i, int j)
//{
//	if (i && j)
//	{
//		ListNode* cur = head;
//		int k = 1;
//		while (i != k)
//		{
//			cur = cur->next;
//			k++;
//		}
//
//		int l = 1;
//		ListNode* tmp = head;
//		while (l != j)
//		{
//			tmp = tmp->next;
//			l++;
//		}
//		cur->rand = tmp;
//	}
//}
//
//void List::Print()
//{
//	ListNode* tmp = head;
//	if (tmp)
//	{
//		while (tmp != tail->next)
//		{
//			if (tmp->rand)
//				std::cout << tmp->data << "\t:\t" << tmp->rand->data << "\n";
//			else
//				std::cout << tmp->data << "\n";
//			tmp = tmp->next;
//		}
//	}
//
//}
//
//ListNode::ListNode()
//{
//	data = "";
//	next = nullptr;
//	prev = nullptr;
//	rand = nullptr;
//}
