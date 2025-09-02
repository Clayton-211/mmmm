#include <iostream>
#include<cstring>
using namespace std;

struct node 
{
    int PRN;
    string nm;
    node* next;  
};

class SLLPinClub 
{
public:
    node* head;
    node* tail;

    SLLPinClub()
    {
        head = tail = nnode;
    }

    void create();
   
};

int main() 
{
    SLLPinClub L1;
    cout << "Welcome to the club\n";
    L1.create();
  
    return 0;
}

void SLLPinClub::create() {
    char ch;
    do
    {
        nnode = new node;  
        nnode->next =NULL ;
        

        cout << "\nEnter PRN no.: ";
        cin >> nnode->PRN;

        cout << "Enter name: ";
        cin >> nnode->nm;

     
    cout<<"/n nnode="<< nnode;
	cout<<"/n head & tail="<<head; 

        cout << "Do you want to continue (y/n)? ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

}
#include <iostream>
using namespace std;

struct node {
	int PRN;
	string nm;
	node* next;   // renamed from node* node;
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
};

int main() {
	SLLPinClub L1;
	cout << "Welcome to the club\n";
	L1.create();
	L1.display();  // display the list after creation
	return 0;
}

void SLLPinClub::create() {
	char ch;
	do {
		node* nnode = new node;  // create new node

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

