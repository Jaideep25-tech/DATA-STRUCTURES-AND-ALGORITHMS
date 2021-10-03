//implement circular linked list in c++
#include<bits/stdc++.h>
using namespace std;
//structure to create linked list
struct node{
    int data;               //contains data to the node
    struct node *next;      //pointer to the next node 
};
struct node *head=NULL;
//method to insert values into the linked list
void insert(int newdata) {
   struct node *newnode = (struct node *)malloc(sizeof(struct node));       //dynamic allocation of memory
   struct node *ptr = head;
   newnode->data = newdata;
   newnode->next = head;
   if (head!= NULL) {
      while (ptr->next != head)
      ptr = ptr->next;
      ptr->next = newnode;
   } else
   newnode->next = newnode;
   head = newnode;
}
//method to display the linked list
void display() {
   struct node* ptr;
   ptr = head;
   do {
      cout<<ptr->data <<" ";
      ptr = ptr->next;
   } while(ptr != head);
}
//driver function
int main() {
   int n;
   cout<<"Enter number of elements of the linked list: ";
   cin>>n;
   cout<<"Insert data into the linked list: "<<endl;
   for(int i=0;i<n;i++){
       int data;
       cin>>data;
       insert(data);                //pushes data from user to the insert() method
   }
   cout<<"The circular linked list is: ";
   display();                       //prints linked list 
   return 0;
}