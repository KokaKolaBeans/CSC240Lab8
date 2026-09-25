//========================================================================
// Name        : CSC240_Queue_Linked.cpp
// Author      : Ivan Temesvari; Rewritten to Circular by Kazim Zaidi
// Version     : 9/25/2026
// Description : Linked Q -> Linked Q Circular; Implement Rule-of-Three
//========================================================================

#include <iostream>
// #include "QueType.h"
using namespace std;

template <class ItemType>

struct NodeType
{
    ItemType info;
    NodeType<ItemType> *next;
};

class FullQueue
{
};
class EmptyQueue
{
};

template <class ItemType>
class QueType
{
public:
    QueType();
    // Class constructor.
    // Because there is a default constructor, the precondition
    // that the queue has been initialized is omitted.
    QueType(int max);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
    QueType(const QueType &anotherQue);
    // Copy constructor
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
    void Dequeue(ItemType &item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
    void Print();
    // Function: Display the contents of the QueType in the console output.
    // Post: The QueType remains unchanged.
    QueType<ItemType> &QueType<ItemType>::operator=(const QueType &anotherQue);

private:
    NodeType<ItemType> *rear;
    int length;
};

template <class ItemType>
void QueType<ItemType>::Print() // rewrote to circular
{
    if (isEmpty())
    {
        throw EmptyQueue;
    }
    else
    {
        NodeType<ItemType> *tempPtr = rear;
        tempPtr = tempPtr->next;
        std::cout << "Front:";
        while (tempPtr != rear)
        {
            std::cout << temp->info << " ";
            tempPtr = tempPtr->next;
        }
        std::cout << tempPtr->info << ":Rear" << endl;
    }
}

template <class ItemType>

QueType<ItemType>::QueType() // Class constructor. // rewrote to circular
// Post:  front and rear are set to NULL.
{
    rear = nullptr;
    length = 0;
}

template <class ItemType>

void QueType<ItemType>::MakeEmpty() // rewrote to circular

// Post: Queue is empty; all elements have been deallocated.
{
    if (IsEmpty()) // special case 0-node
    {
        return; // throwing here is a poor design decision
    }

    NodeType<ItemType> *tempPtr;
    tempPtr = rear->next; // tempPtr -> first node
    rear->next = nullptr; // final element is marked

    while (tempPtr->next != nullptr) // after while, tempPtr -> final node
    {
        rear = tempPtr;
        tempPtr = tempPtr->next;
        delete rear;
    }
    delete tempPtr; // final node; special case 1-node;
    rear = nullptr; // empty queue invariant
    length = 0;
}

// Class destructor.
template <class ItemType> // this works - no backing structure to delete after MakeEmpty(); no rewrite to circular
QueType<ItemType>::~QueType()
{
    MakeEmpty();
}

template <class ItemType> // no rewrite to circular
bool QueType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
    NodeType<ItemType> *location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc &)
    {
        return true;
    }
}

template <class ItemType> // rewrote to circular
bool QueType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
    // return (rear == nullptr);
    return (length == 0);
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem) // rewrote to circular
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized.
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.

{
    if (IsFull())
        throw FullQueue();
    else
    {
        NodeType<ItemType> *newNode;
        newNode = new NodeType<ItemType>; // pointer to newNode
        newNode->info = newItem;

        if (isEmpty())
        {
            rear = newNode;
            newNode->next = rear;
        }
        if (!isEmpty())
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        length++;
        // rear = newNode;
    }
}

template <class ItemType> // rewrote to circular
void QueType<ItemType>::Dequeue(ItemType &item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty()) // special case 0-node
    {
        throw EmptyQueue();
    }
    else if (rear->next == rear) // special case 1-node
    {
        delete rear;
        rear = nullptr;
    }
    else // general case n-node
    {

        NodeType<ItemType> *tempPtr;

        tempPtr = rear->next;          // tempPtr points to first element
        rear->next = rear->next->next; // last element points to second element
        delete tempPtr;
    }
    length--;
    return;
}

template <class ItemType> // rewrote to circular
QueType<ItemType>::QueType(const QueType &anotherQue)
{
    NodeType<ItemType> *ptr1;
    NodeType<ItemType> *ptr2;
    if (anotherQue.IsEmpty()) // special case 0-node
    {
        length = 0;
        rear = nullptr;
        return;
    }
    else if (anotherQue.rear->next == anotherQue.rear) // special case 1-node
    {
        ptr1 = new NodeType<ItemType>;
        ptr2 = anotherQue.rear;
        ptr1->info = ptr2->info;
        rear = ptr1;
        length = 1;
        return;
    }
    else // general case n-node
    {

        ptr2 = anotherQue.rear->next;
        ptr1 = new NodeType<ItemType>;
        NodeType<ItemType> *front = ptr1;
        ptr1->info = ptr2->info;
        for (int k = 0; k < anotherQue.length - 1; k++)
        {
            ptr2 = ptr2->next;
            ptr1->next = new NodeType<ItemType>;
            ptr1 = ptr1->next;
            ptr1->info = ptr2->info;
        }
        ptr1->next = front;
        length = anotherQue.length;
        rear = ptr1;
    }
}

template <class ItemType>
QueType<ItemType> &QueType<ItemType>::operator=(const QueType &anotherQue)
{
    return *this;
}

int main()
{
    QueType<int> q;
    q.Enqueue(8);
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(5);
    q.Enqueue(3);
    q.Enqueue(0);
    q.Enqueue(9);
    q.Print();
    int numFront;
    q.Dequeue(numFront);
    cout << numFront << endl;
    q.Print();
    return 0;
}
