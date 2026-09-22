#ifndef QUEUETYPE_H
#define QUEUETYPE_H
#include <iostream>
#include <cmath>
using namespace std;
class FullQueue
{};  
class EmptyQueue
{};  
typedef char ItemType;
class QueType
{
public: 
	friend ostream& operator<<(ostream& out, const QueType& q);

    QueType();
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.
    QueType(int max);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.

    ItemType DequeueRear();   //IT 3/4/2020
    //Function: Remove and return the rear item of a queue

    void evacuate(int num);
private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
};


QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}
#endif

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       otherwise a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}

ItemType QueType::DequeueRear(){
	ItemType item;
	 if (IsEmpty())
	    throw EmptyQueue();
	  else
	  {
		  item = items[rear];
		  rear = (rear - 1 + maxQue) % maxQue;
	  }
	 return item;
}


void QueType::evacuate(int num){
	cout << "rear = " <<  rear << " front: " << front << endl;
	for(int i = 0; i < num; i++){
		if(IsEmpty()){
			throw EmptyQueue();
		}
		DequeueRear();
	}
}



ostream& operator<<(ostream& out, const QueType& q){
	if((q.rear - q.front + q.maxQue) % q.maxQue == 0){
		out << "Empty queue." << endl;
	}
	else{
		out << "Front: ";
		for(int i = 0; i < (q.rear - q.front + q.maxQue) % q.maxQue; i++){
			out << q.items[(q.front + 1 + i) % q.maxQue] << " ";
		}
		out << endl;
	}
	return out;
}











