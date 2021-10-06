#include<iostream>
using namespace std;
 
// Maximum size of array or Dequeue
#define MAX 100
 
class Deque
{
    int  arr[MAX];
    int  front;
    int  rear;
    int  size;
public :
    Deque(int size) //constructor to intialise size of Dequeue
    {
        front = -1;
        rear = 0;
        this->size = size;
    }
 
    // Operations that can be performed on Dequeue
    void  insertfront(int key);
    void  insertrear(int key);
    void  deletefront();
    void  deleterear();
    bool  isFull();
    bool  isEmpty();
    void display();
    int  getFront();
    int  getRear();   
};
 
// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size-1)||
            front == rear+1);
}
 
// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
    return (front == -1);
}
 
// Inserts an element at front
void Deque::insertfront(int key)
{
    // check whether Deque if  full or not
    if (isFull())
    {
        cout << "Overflow\n" << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // front is at first position of queue
    else if (front == 0)
        front = size - 1 ;
 
    else 
        front = front-1;
 
    // insert current element into Deque
    arr[front] = key ;
}
 
// function to insert element at rear end of Deque.
void Deque ::insertrear(int key)
{
    if (isFull())
    {
        cout << " Overflow\n " << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // rear is at last position of queue
    else if (rear == size-1)
        rear = 0;
 
    // increment rear end by '1'
    else
        rear = rear+1;
 
    // insert current element into Deque
    arr[rear] = key ;
}
 
// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << "Queue Underflow\n" << endl;
        return ;
    }
 
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size -1)
            front = 0;
 
        else // increment front by '1' to remove current
            // front value from Deque
            front = front+1;
}
 
// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty())
    {
        cout << " Underflow\n" << endl ;
        return ;
    }
 
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}
 
// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[front];
}
 
// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[rear];
}
//function to diplay Dequeue
void Deque::display()
{
    if(isEmpty())
    {
        cout<<"Deque is empty!!";
        return;
    }
    int i=front;
    cout<<"the elements of dequeue are:";
    while(i!=rear)
    {
        cout<<arr[i]<<" ";
        i=(i+1)%size;
    }
    cout<<arr[i]<<" ";
}
 
// main function
int main()
{
    int ch=1,key;
    Deque dq(5);
    do{
        
    cout<<"1.insert at front"<<endl;
    cout<<"2.insert at end"<<endl;
    cout<<"3.delete from front"<<endl;
    cout<<"4.delete from end"<<endl;
    cout<<"5.get front element"<<endl;
    cout<<"6.get rear element"<<endl;
    cout<<"7.Display deueue elements"<<endl;
    cout<<"8.Exit"<<endl;
    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"enter the element to be inserted in front: ";
        cin>>key;
        dq.insertfront(key);
        break;
        case 2:cout<<"enter the element to be inserted at rear: ";
        cin>>key;
        dq.insertrear(key);
        break;
        case 3:dq.deletefront();
        break;
        case 4:dq.deleterear();
        break;
        case 5:cout<<dq.getFront()<<endl;
        break;
        case 6:cout<<dq.getRear()<<endl;
        break;
        case 7:dq.display();
        break;
        case 8:exit(0);
        break;
    }
    }while(ch);
    
    return 0;
}