#include<bits/stdc++.h>
using namespace std;

// declare a node of linked list
struct Node{
    int data;
    struct Node* next;
}*top;

// function to insert element into stack
void push(int data){

    // create new node and allocate memory
    struct Node* temp = new Node();

    //check whether stack is full or not
    if(!temp){
        cout<<"Stack Overflow";
        exit(1);
    }

    //Insert data into node
    temp->data = data;
    //make temp next point to current top
    temp->next = top;
    //make temp as current top
    top = temp;
}

// function to pop top element from stack 
void pop(){
    struct Node* temp;

    //if stack is empty there's nothing to pop
    if( top == NULL){
        cout<<"Stack underflow"<<endl;
        exit(1);
    }
    else{
        temp = top;
        top = top->next;
        temp->next = NULL;
        //release memory from top node
        free(temp);
    }
}

// function to check whether stack is empty or not 
int isEmpty(){
    return top == NULL;
}

//function to get top element in stack
int topElement(){
    if( !isEmpty())
        return top->data;
    else 
        return -1;
}

// function to print all elements of stack 
void display(){
    struct Node* temp;

    if( top == NULL ){
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    else{
        temp = top;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

int main(){
    int choice;
    while(true){
        cout<<"Enter 1 to push in stack:\n";
        cout<<"Enter 2 to pop from stack:\n";
        cout<<"Enter 3 to display stack:\n";
        cout<<"Enter 4 to get top element in stack:\n";
        cout<<"Enter 5 exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1 : int x;
                    cout<<"Enter element to push: ";
                    cin>>x;
                    push(x);
                    break;
            case 2 : pop();
                    break;
            case 3 : display();
                     cout<<endl;
                     break;
            case 4 : int temp ;
                     temp = topElement();
                     if( temp != -1)
                        cout<<temp<<endl;
                     else
                        cout<<"Stack is empty"<<endl;
                     break;

            case 5 : exit(1);
        }
    }
    return 0;
}

