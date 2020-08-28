#pragma once

#include "JosephusNode.h"


class Josephus {
public:
	Josephus();
	Josephus(int, int);
	~Josephus();

	void AddPerson(JosephusNode*);
	void Kill(int, int, int, JosephusNode*);

	void display(JosephusNode*);


private:
	//bool left;
	//bool right;
	int numOfPeople;
	int numToSkip;
	JosephusNode* head;
	JosephusNode* tail;
};

