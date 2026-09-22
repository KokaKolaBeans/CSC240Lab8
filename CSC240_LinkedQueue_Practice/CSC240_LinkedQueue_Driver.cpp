//============================================================================
// Name        : CSC240_Queue_Linked.cpp
// Author      : Ivan Temesvari
// Version     : 2/28/2022
// Copyright   : Your copyright notice
// Description : Practice with the Linked Queue and Templates
//============================================================================

#include <iostream>
#include "QueType.h"
using namespace std;

int main() {
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
