#include<iostream>
using namespace std;
class node{
public:
	int data;
	node *next;
	node *prev;
};

int main(){
	node *head=NULL;
	node *first=new node();
	node *second=new node();
	node *third=new node();
	
	head->data=10;
	head->next=first;
	head->prev=NULL;
	first->data=20;
	first->next=second;
	first->prev=head;
	second->data=30;
	second->next=third;
	second->prev=first;
	third->data=40;
	third->next=NULL;
	third->prev=second;
	
	return 0;
}DATA-STRUCTURES-AND-ALGORITHMS/01. DataStructures/01. Linked List/2. Doubly-Linked-List/Basic Operations