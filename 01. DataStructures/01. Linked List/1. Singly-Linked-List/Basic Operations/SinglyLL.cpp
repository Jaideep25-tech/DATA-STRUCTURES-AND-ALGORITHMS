/*
Sample Input:
After Inserting: 10 20 30 40 50 60
Sample Output:
10->20->30->40->50->60->NULL
*/


// Including header file.
#include<iostream>  // for using cout/cin
using namespace std;

// Defination of Node class.
class Node{
    // Private data members.
    int data;
    Node* next;
    public:
        // Declaration of construstor.
        Node(int data);
        // Declaration of member functions.
        void insert(int data);
        void print();
};

// Defination of constuctor.
Node::Node(int data){
    this->data = data;
    this->next = nullptr;
}

// Defination of insert() fucntion,
// to insert Node in the Linked List.
void Node::insert(int data){
    Node* itr = this;
    while(itr->next)
        itr = itr->next;
    itr->next = new Node(data);
}

// Defination of print() fucntion,
// to print data of all Nodes of the Linked List.
void Node::print(){
    Node* itr = this;
    while(itr){
        if(itr->next)
            cout<< itr->data<< "->";
        else
           cout<< itr->data<< "->NULL";
        itr = itr->next;
    }    
}

// main() function or the driver function.
int main(){
    // Instantiating Node class,
    // and inserting elements in a Linked List.
    Node *LinkedList = new Node(10);
    LinkedList->insert(20);
    LinkedList->insert(30);
    LinkedList->insert(40);
    LinkedList->insert(50);
    LinkedList->insert(60);

    cout<< "\nYour Linked List Is :"<< endl;
    LinkedList->print();

    return 0;
    // End of main function.
}