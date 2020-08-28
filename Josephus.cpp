#include "JosephusNode.h"
#include "Josephus.h"

#include <string>
#include <iostream>

using namespace std;

Josephus::Josephus() {
	numOfPeople = 0;
	numToSkip = 0;
	head = nullptr; 
	tail = nullptr;
}


Josephus::Josephus(int size, int skip) {
	numOfPeople = size;
	numToSkip = skip;
	head = nullptr;
	tail = nullptr;
}

Josephus::~Josephus() {
	JosephusNode* temp = head;

	while (temp) {
		JosephusNode* next = temp->GetNext();
		delete temp;
		temp = next;
	}
}

void Josephus::AddPerson(JosephusNode* person) {
	if (head == nullptr) {
		head = person;
		tail = person;
	}
	else {
		tail->InsertAfter(person);
		tail = person;
		tail->SetNext(head);
	}
}


void Josephus::Kill(int size, int start, int skip, JosephusNode* temp) {
	JosephusNode* killNode = nullptr;
	if (temp != nullptr) {
		killNode = head;
		do {
			if (killNode == nullptr) {
				cout << "NULL" << endl;
			}
			if (killNode->GetID() == start) {
				//cout << "MATCHED!" << endl;
				break;
			}

			killNode = killNode->GetNext();
		} while (killNode != head);
	}
	//cout << "Start position given: " << start << endl;
	//cout << "KillNode position: " << killNode->GetID() << endl;
	JosephusNode* tempNode = killNode;
	while (size > 1) {
		//cout << "SIZE: " << size << endl;
		int count = skip;
		while (count > 1) {
			killNode = killNode->GetNext();
			count--;
		}
		//cout << "TEMPNODE BEFORE: " << tempNode->GetPlayerName() << endl;
		//cout << "KILLNODE BEFORE: " << killNode->GetPlayerName() << endl;
		if (size > 2) {
			while (tempNode->GetNext() != killNode) {
				tempNode = tempNode->GetNext();
			}
			//cout << "PLAYER BEFORE: " << tempNode->GetPlayerName() << endl;
			tempNode->SetNext(killNode->GetNext());
			//cout << "TEMPNODE->NEXT: " << tempNode->GetNext()->GetPlayerName() << endl;
			tempNode = killNode->GetNext();
			if (killNode == head) {
				head = head->GetNext();
			}
			delete killNode;
			killNode = tempNode;
			//cout << "TEMPNODE AFTER: " << tempNode->GetPlayerName() << endl;
			//cout << "KILLNODE AFTER: " << killNode->GetPlayerName() << endl;
			display(tempNode);
			size--;
		}
		else {
			size--;
			tempNode->SetNext(killNode->GetNext());
			tempNode = killNode->GetNext();
			if (killNode == head) {
				head = head->GetNext();
			}
			delete killNode;
			//cout << "GAME OVER" << endl;
			//cout << "SIZE: " << size << endl;
			cout << "WINNER: " << tempNode->GetPlayerName() << endl;
			//cout << "NEXT: " << tempNode->GetNext()->GetPlayerName() << endl;
			return;

		}
	}
}

void Josephus::display(JosephusNode* temp) {
	JosephusNode* current = nullptr;
	string name;
	if (temp != nullptr) {
		//temp = head;
		if (head != nullptr) {
			current = head;
			//cout << "!!!!!!!!!!!!!!!!!" << endl;
			//cout << "-------------" << head->GetPlayerName() << endl;
		}
		else {
				current = head->GetNext();
		}
		do {
			name = current->GetPlayerName();
			//cout << "NAME: " << name << endl;
			do {
				current = current->GetNext();
			} while (current->GetNext() == nullptr);
		} while (current != head);
	}

	//cout << "Done displaying" << endl;


}