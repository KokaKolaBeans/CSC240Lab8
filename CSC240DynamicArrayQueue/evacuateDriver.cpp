/*
 * evacuateDriver.cpp
 *
 *  Created on: Mar 4, 2020
 *      Author: Ivan
 */
#include <iostream>
#include <random>
#include <ctime>
#include "QueType.h"
using namespace std;

int main(){
	const int NUM_CUSTOMERS = 50;
	const int NUM_CHARACTERS = 26;
	QueType line(NUM_CUSTOMERS);
	int numEvacuate;
	int numRemoved = 0;
	char evacuee;
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
						'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	srand(time(0));

	QueType testLine(2);
	testLine.Enqueue('a');
	cout << testLine << endl;
	testLine.Enqueue('b');
	cout << testLine << endl;

	for(int i = 0; i < NUM_CUSTOMERS; i++){
		char randChar;
		randChar = alphabet[rand() % NUM_CHARACTERS];
		//cout << randChar << endl;
		line.Enqueue(randChar);
	}

	//Before evacuate
	cout << "Before evacuation:\n" << line << endl;

	cout << "How many characters should evacuate from the rear?";
	cin >> numEvacuate;
	line.evacuate(numEvacuate);
	numRemoved += numEvacuate;

	//after evacuate
	cout << "After evacuation:\n" << line << endl;

	cout << "Rear item in line dequeued: " << line.DequeueRear() << endl;
	cout << line << endl;
	numRemoved++;

	line.Dequeue(evacuee);
	cout << "Front item in line dequeued: " << evacuee << endl;
	cout << line << endl;
	numRemoved++;

	line.evacuate(NUM_CUSTOMERS - numRemoved - 1);
	cout << "Evacuate all but one:\n" << line << endl;
	numRemoved += (NUM_CUSTOMERS - numRemoved - 1);

	line.evacuate(1);
	cout << "Evacuate last one:\n" << line << endl;


	return 0;
}

