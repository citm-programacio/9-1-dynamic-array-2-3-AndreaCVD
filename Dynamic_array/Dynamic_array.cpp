//Write a program that asks for numbers from the user, one by one.
//Every time a number is entered, it is added to an array.But the array must always keep the numbers in order.
//
//189 ->[189]
//50 ->[59, 189]
//111 ->[59, 111, 189]
//
//Print the complete array every time a new number is entered.
//You must not declare a static array with arbitrary length!
//Create a new dynamic array bigger every time, deleting the old one.
#include <iostream>
using namespace std;

int main() {
	int size = 0, num;
	
	string option;

	int* arr = new int[0]; //Empty dynamic array

	while (true) {

		cout << "Insert number: | -1 to stop" << endl;
		cin >> num;

		if (num == -1) {
			break;
		}

		// Create new dynamic array which will be sorting the numbers
		int* newArr = new int[size + 1];
		
		// Find the correct position to insert the new number
		int i = size - 1;

		// Shift elements to the right to make space for the new number
		while (i >= 0 && arr[i] > num) {
			newArr[i + 1] = arr[i];  // Shift element to the right
			i--;
		}

		newArr[i + 1] = num;

		// Copy the rest of the elements into the new array (if any)
		for (int j = 0; j < i + 1; ++j) {
			newArr[j] = arr[j];
		}

		// Delete the old array to free memory
		delete[] arr;

		// Point arr to the new array
		arr = newArr;

		++size;

		for (int i = 0; i < size; ++i) {
			cout << "[ " << newArr[i] << " ] ";
		}

	}


	// Free dynamically allocated memory
	delete[] arr;


}