#include "JosephusNode.h"

#include <string>

using namespace std;


JosephusNode::JosephusNode(int id, string name) {
	this->id = id;
	this->name = name;
	next = nullptr;
}

void JosephusNode::InsertAfter(JosephusNode* person) {
	JosephusNode* tmpNext = nullptr;

	tmpNext = this->next;    // Remember next
	this->next = person;    // this -- node -- ?
	person->next = tmpNext;
}

JosephusNode* JosephusNode::GetNext() {
	return next;
}

void JosephusNode::SetNext(JosephusNode* ptr) {
	next = ptr;
}

int JosephusNode::GetID() {
	return id;
}

string JosephusNode::GetPlayerName() {
	return name;
}