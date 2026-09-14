/*
 * doublePointer.cpp
 *
 *  Created on: Oct 29, 2018
 *      Author: itemesva
 */
#include <iostream>
using namespace std;

int main(){
	int y = 5;
	cout << y << endl;
	int* z = &y;   //a pointer to an integer, a.k.a. an int pointer
	cout << *z << endl;   //use the dereference operator (i.e., *) to access the contents of where z points to
	int** a = &z;   //double pointer, a.k.a. a pointer to a pointer
	cout << "This is the value stored at the memory location of a: " << a << endl;
	cout << "This is the address stored at the memory location of z: " << *a << endl;
	cout << "This is the address of y: " << &y << endl;
	cout << "This is the value of the double pointer a: " << *(*a) << endl; //I want 5 to be displayed here.

	int value = 6;
	int* valuePtr = &value;

	cout << "value: " << value << endl;
	cout << "dereferenced valuePtr: " << *valuePtr << endl;

	value = 9;
	cout << "dereferenced (after change of value) valuePtr: " << *valuePtr << endl;


	//Create a 2-D array using a double pointer.
	int** myArray = new int*[4];
	myArray[0] = new int[4];
	myArray[1] = new int[4];
	myArray[2] = new int[4];
	myArray[3] = new int[4];


	myArray[0][0] = 5;    //address of myArray
	myArray[0][1] = 6;
	myArray[0][2] = -2;
	myArray[0][3] = 3;

	myArray[1][0] = 8;    //address of (myArray+1)
	myArray[1][1] = 10;
	myArray[1][2] = 12;
	myArray[1][3] = 3;

	myArray[2][0] = 6;
	myArray[2][1] = 9;
	myArray[2][2] = -4;
	myArray[2][3] = 2;

	myArray[3][0] = 4;
	myArray[3][1] = 9;
	myArray[3][2] = 2;
	myArray[3][3] = -6;

	cout << "The address of myArray: " << myArray << "\tContains the value: " << *myArray
		 << "\nWhich contains the value of: " << *(*myArray) << endl;
	cout << "The address of myArray+1 (second row): " << (myArray+1) << endl;
	cout << "\tThe fist item in the second row: " << *(*(myArray+1)) << " at address: " << *(myArray+1) << endl;



	//Delete the dynamically allocated memory for our 2-D array.
	//delete myArray;  //NO GOOD! memory leak!

	//Clean it up properly. GOOD! no memory leak!
	for(int i = 0; i < 4; i++){
		delete [] myArray[i];
	}
	delete [] myArray;

	int myArr[50];  //static--fixed size before runtime.

	//Create an array dynamically, since we don't know what size will be until runtime.
	int size;
	cout << "Enter the size: " << endl;
	cin >> size;
	int* array = new int[size];
	cout << "Enter the elements of the array: " << endl;
	for(int i = 0; i < size; i++){
		cin >> array[i];
	}

	cout << "array contents: ";
	for(int i = 0; i < size; i++){
			cout << array[i] << " ";
	}

	//**********************************************************************
	//We can observe the ramifications of a memory leak and shallow copying:
	cout << "\ncopyArray contents: ";
	int* copyArray = array; //shallow copy assignment
	for(int i = 0; i < size; i++){
		cout << copyArray[i] << " ";
	}
	array[4] = 199;
	cout << "\narray contents: ";
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	delete array;  //this memory is free/released by the program stack now!
	//comment and uncomment the line above to observe the difference in output.
	int* bankAccountPrincipal = new int[5000];
	bankAccountPrincipal[0] = -3498037;
	cout << "\ncopyArray contents (after newly allocated memory): ";
	for(int i = 0; i < size; i++){
		cout << copyArray[i] << " ";
	}
	//**********************************************************************

	//deep copy: avoid a bad pointer dereference
	copyArray = new int[size];
	for(int i = 0; i < size; i++){
		copyArray[i] = array[i];
	}
	array[4] = 299;
	cout << "\narray contents: ";
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << "\ncopyArrayV2 contents: ";
	for(int i = 0; i < size; i++){
		cout << copyArray[i] << " ";
	}
}


