#include "Josephus.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void display(JosephusNode*);


int main(int agrc, char* argv[]) {

	// this shows files in the directory
	//char command[10] = "dir";
	//system(command);
	//return 0;


	cout << "HELLO" << endl;
	cout << "Argument = " << argv[1] << endl;

	int id = 1;
	int people, skips, startingPoint;
	string dir;
	string name;
	ifstream inFile;
	// make sure file path is accurate
	string filename = argv[1];
	cout << filename << endl;

	inFile.open(filename);

	if (!inFile) {
		cout << "File isn't open" << endl;
		return 1;
	}
	else 
		cout << "File opened" << endl;
	

	Josephus list;
	JosephusNode* nameNode = nullptr;
	//while (getline(inFile, name)) {
	//	cout << "PLAYER " << id << ": " << name << endl;
	//	nameNode = new JosephusNode(id, name);
	//	list.AddPerson(nameNode);
	//	id++;
	//}

	cout << "How many people will be participating today? " << endl;
	cin >> people;
	cout << "Where would you like to start? " << endl;
	cin >> startingPoint;
	cout << "How many people would you like to skip? " << endl;
	cin >> skips;

	int numPeople = people;
	while (getline(inFile, name) && numPeople > 0) {
		//cout << "PLAYER " << id << ": " << name << endl;
		nameNode = new JosephusNode(id, name);
		list.AddPerson(nameNode);
		id++;
		numPeople--;
	}

	list.display(nameNode);
	list.Kill(people, startingPoint, skips, nameNode);

	inFile.close();

	return 0;
}