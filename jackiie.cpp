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
    void insertAtPosition(); 
};

int main() {
    SLLPinClub L1;
    cout << "Welcome to the club\n";
    L1.create();
    L1.display();

    cout << "\nInsert a new member at a position:\n";
    L1.insertAtPosition();
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

void SLLPinClub::insertAtPosition() {
    int pos;
    cout << "Enter the position to insert new member (starting from 1): ";
    cin >> pos;

    if (pos < 1) {
        cout << "Invalid position\n";
        return;
    }

    node* nnode = new node;
    cout << "Enter PRN no.: ";
    cin >> nnode->PRN;
    cout << "Enter name: ";
    cin >> nnode->nm;
    nnode->next = NULL;

    if (pos == 1) {
      
        nnode->next = head;
        head = nnode;
        if (tail == NULL) {  
            tail = nnode;
        }
        return;
    }

 
    node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range. Inserting at end.\n";
        if (tail != NULL) {
            tail->next = nnode;
            tail = nnode;
        }
        else {
            head = tail = nnode;
        }
    }
    else {
        nnode->next = temp->next;
        temp->next = nnode;
        if (nnode->next == NULL) {
            tail = nnode; 
        }
    }
}

