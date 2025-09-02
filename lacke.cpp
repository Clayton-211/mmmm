#include<iostream>
#include<cstring>
using namespace std;

struct node {
	int PRN;
	string nm;
	node* next;    
};

class SLLPinClub {
public:
	node* head;
	node* tail;

	SLLPinClub() {
		head = tail = NULL;
	}

	void create();
	void display();
	void deleteByPRN();
};

int main() {
	SLLPinClub L1;
	cout << "Welcome to the club\n";
	L1.create();
	L1.display();

	cout << "\nDelete a member by PRN:\n";
	L1.deleteByPRN();
	L1.display();

	return 0;
}

void SLLPinClub::create() {
	char ch;
	do {
		node* nnode = new node; 

		cout << "\nEnter PRN no.: ";
		cin >> nnode->PRN;

		cout << "Enter name: ";
		cin >> nnode->nm;

		nnode->next = NULL;  

		if (head == NULL) {
			head = tail = nnode; 
		}
		else {
			tail->next = nnode; 
			tail = nnode;       
		}

		cout << "Do you want to continue (y/n)? ";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');

	if (head == NULL) {
		cout << "\nClub is empty\n";
	}
}

void SLLPinClub::display() {
	if (head == NULL) {
		cout << "\nClub is empty\n";
		return;
	}

	cout << "\nClub Members:\n";
	node* temp = head;
	while (temp != NULL) {
		cout << "PRN: " << temp->PRN << ", Name: " << temp->nm << endl;
		temp = temp->next;
	}
}

void SLLPinClub::deleteByPRN() {
	if (head == NULL) {
		cout << "Club is empty. Nothing to delete.\n";
		return;
	}

	int key;
	cout << "Enter PRN number to delete: ";
	cin >> key;

	node* temp = head;
	node* prev = NULL;

	while (temp != NULL && temp->PRN != key) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		cout << "Member with PRN " << key << " not found.\n";
		return;
	}

	if (temp == head) {
		head = head->next;
		if (head == NULL) {  
			tail = NULL;
		}
		delete temp;
		cout << "Member with PRN " << key << " deleted from the club.\n";
		return;
	}

	if (temp == tail) {
		tail = prev;
		tail->next = NULL;
		delete temp;
		cout << "Member with PRN " << key << " deleted from the club.\n";
		return;
	}

	prev->next = temp->next;
	delete temp;
	cout << "Member with PRN " << key << " deleted from the club.\n";
}

