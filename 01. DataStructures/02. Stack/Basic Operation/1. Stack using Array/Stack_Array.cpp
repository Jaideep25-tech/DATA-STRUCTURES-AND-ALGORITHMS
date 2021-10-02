#include <bits/stdc++.h>
using namespace std;
#define MAX 100 // Maximum size of Stack
 
class Stack {
    int top;
 
    public:
        int a[MAX]; 
    
        Stack() { top = -1; }
        void push(int x);
        void pop();
        int topElement();
        bool isEmpty();
        void display();
};
 
void Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout<<"Stack Overflow";
    }
    else {
        a[++top] = x;
    }
}
 
void Stack::pop()
{
    if (top < 0) {
        cout<<"Stack Underflow";
    }
    else {
        top--;
    }
}
int Stack::topElement()
{
    if (top < 0) {
        cout<<"Stack is Empty";
        return -1;
    }
    else {
        int x = a[top];
        return x;
    }
}

void Stack::display(){
    if( top < 0){
        cout<<"Stack is empty"<<endl;
        exit(1);
    }
    else{
        int temp = top;
        while( temp >= 0){
            cout<<a[temp--]<<" ";
        }
        cout<<endl;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}
 
int main()
{
    class Stack s;
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
                    s.push(x);
                    break;
            case 2 : s.pop();
                     break;
            case 3 : s.display();
                     break;
            case 4 : int temp ;
                     temp = s.topElement();
                     if( temp != -1)
                        cout<<temp<<endl;
                     break;

            case 5 : exit(1);
        }
    }
    return 0;
}