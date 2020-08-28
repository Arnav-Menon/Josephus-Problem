#pragma once
#include <string>

using namespace std;

class JosephusNode {
public:
	JosephusNode(int, string);
	void InsertAfter(JosephusNode*);
	JosephusNode* GetNext();
	int GetID();
	void SetNext(JosephusNode* ptr);
	string GetPlayerName();

private:

	int id;
	string name;
	JosephusNode* next;

};

