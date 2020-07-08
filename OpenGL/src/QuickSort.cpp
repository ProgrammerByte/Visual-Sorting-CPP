#include "QuickSort.h"

QuickSort::QuickSort(vector<float>& contents, int length) :Algorithm(contents, length) {
	for (int i = 0; i < length; i++) {
		pivots.push_back(false);
	}
	this->currentPivot = 0;
	this->pointer = 1;
	//this->nonPivot = false; //whether a non-pivot value has been found within the current iteration
}

bool QuickSort::cycle() {
	this->clearColours();

	while (true) { //repeats the cycle until something has happened
		if (pointer >= length) { //if at the end of the list
			if (currentPivot < length) {
				pivots[currentPivot] = true;
			}
			pointer = 0;

			for (int i = 0; i < length; i++) {
				if (pivots[i] == false) {
					currentPivot = i;
					pointer = i + 1;
					break;
				}
			}
			if (pointer == 0) { //if all values are pivots
				return true;
			}
		}
		else if (pivots[pointer] == true) { //if at the next pivot
			pivots[currentPivot] = true;
			currentPivot = pointer + 1;
			pointer += 2;
		}
		else {
			if (contents[pointer] < contents[currentPivot]) { //shifts all values forward to insert a value right before the pivot
				float tempVal = contents[pointer];
				for (int i = pointer; i > currentPivot; i--) {
					contents[i] = contents[i - 1];
				}
				colours[currentPivot] = 1;
				contents[currentPivot] = tempVal;
				currentPivot += 1;
				pointer += 1;
				break;
			}
			pointer += 1;
		}
	}
	return false;
}