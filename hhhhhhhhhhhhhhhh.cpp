#include<cstring>
#include<iostream>
using namespace std ;
 struct node
  {
	int PRN;
	string nm;
	node*node;
  };
node*temp,*temp1;
class SLLPinClub
 {
	public:
	       node*head,*tail;
		   SLLPinClub()
		   {
		   	head=tail=NULL;
		   }
	void create();
	void display();
 }; 
int main()
 {
	SLLPinClub L1;
	cout<<"welcome to the club";
	L1.create();
 }
void SLLPinClub :: create()
 {
	if (head=NULL)
	cout<<"/n club is empty";
 }

char ch;
do {
    nnode = new node;+
    cout<<"/n enter prn no.";
    cin>> nnode->PRN;
    cout<<"/n enter name";
    cin>> nnode-> nm;
    
	cout<<"/n do you want to continueZzz(y/n)?";
	cin>>ch;
    }
while (ch == 'y'|| ch == 'y');
}
