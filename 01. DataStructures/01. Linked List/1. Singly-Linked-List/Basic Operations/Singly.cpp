#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

void Traversing(Node *n){
	int counter=0;
	while(n!=NULL){
		cout<<"\n data in the linked list is"<<n->data;
		n=n->next;
		counter=counter+1;
	}
	cout<<"\n number of nodes in the linkedlist is"<<counter;
}

int main(){
	Node *head=new Node();
	Node *first=new Node();
	Node *second=new Node();
	Node *third=new Node();
	
	head->data=10;
	head->next=first;
	first->data=20;
	first->next=second;
	second->data=30;
	second->next=third;
	third->data=40;
	third->next=NULL;
	
	Traversing(head);
	return 0;
}
