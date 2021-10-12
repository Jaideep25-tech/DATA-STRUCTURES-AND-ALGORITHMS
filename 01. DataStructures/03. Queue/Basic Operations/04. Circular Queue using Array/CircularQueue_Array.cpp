// Including header files.
#include<iostream>  // For cout and cin.
#include<cstdlib>   // For malloc().
#include<vector>    // For displaying Queue.
using namespace std;

// Defination of Queue class.
class Queue{
	// Declaration of private members.
    private: 
        int rear;
        int front;
        int capacity;
        int *arr;
	// Declaration of members functions.
    public: 
        Queue(int);
        bool isEmpty();
        bool isFull();
        void enQueue(int);
        int deQueue();
};

// Queue class Constructor.
Queue::Queue(int capacity){
	this->capacity = capacity;
	this->arr = (int *)malloc(sizeof(int)*capacity);
	this->front = this->rear = -1;
}

// isEmpty() fucntion will return true,
// if the Queue is empty, else it will return false.
bool Queue::isEmpty(){
	return (this->rear == -1) and (this->front == -1);
}

// isFull() fucntion will return true,
// if the Queue is full, else it will return false.
bool Queue::isFull(){
	return (this->front) == (this->rear+1)%this->capacity;
}

// enQueue() function to insert an element in a Queue,
// if Queue is full it will give Overflow.
void Queue::enQueue(int data){
	if(isEmpty()){
		this->front = this->rear = 0;
		this->arr[this->rear] = data;
	}
	else{
		this->rear = (this->rear+1)%this->capacity;
		this->arr[this->rear] = data;
	}
}

// deQueue() function to remove an element from a Queue,
// if Queue is empty it will give Underflow.
int Queue::deQueue(){
	int element = this->arr[this->front];
	if(this->rear == this->front)
		this->rear = this->front = -1;
	else
		this->front = (this->front+1)%this->capacity;
	return element;
}

// main function or the driver function.
int main(){
	// Variable for taking input of capacity from the user.
	int capacity = 0;
	cout<< "\nEnter the capacity of Queue: ";
	scanf("%d", &capacity);

	// Creating Queue of size Capacity.
	Queue *Q = new Queue(capacity);

	// Operation of Queue,
	// Executing according to the user choice.
	while(true){
		cout<< "\n1 - EnQueue: "<< endl;
		cout<< "2 - DeQueue: "<< endl;
		cout<< "3 - Display: "<< endl;
		cout<< "4 - Exit: "<< endl;
		cout<< "\nEnter Your Choice: ";

		int choice;
		cin>> choice;
		switch(choice){
			case 1:{
				if(!Q->isFull()){
					cout<< "\nEnter data to EnQueue: ";
					int data;
					cin>> data;
					Q->enQueue(data);
				}
				else
					cout<< "\nQueue Is Overflow!"<< endl;
				break;
			}
			case 2:{
				if(!Q->isEmpty())
					cout<< "\nDeQueue Element Is : "<< Q->deQueue()<< endl;
				else
					cout<< "\nQueue Is Undeflow!"<< endl;
				break;
			}
			case 3:{
				if(!Q->isEmpty()){
					cout<< "\nElements of a Queue are: "<< endl;
					vector<int> elements;
					while(!Q->isEmpty())
						elements.push_back(Q->deQueue());
					for(auto x: elements){
						Q->enQueue(x);
						cout<< x<< "\t";
					}
					elements.clear();
					cout<< endl;
				}
				else
					cout<< "\nQueue Is Empty!"<< endl;
				break;
			}
			case 4:{
				cout<< "\nExit Successfully!"<< endl;
				exit(0);
				break;
			}
			default:
				cout<< "\nInvalid Choice!"<< endl;
		}
	}

	return 0;
	// End of main function.
}