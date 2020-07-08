#include "MergeSort.h"

MergeSort::MergeSort(vector<float>& contents, int length) :Algorithm(contents, length) {
	this->sublistSize = 1;
	this->ptr1 = 0; //points to the beginning of the first sublist
	this->ptr2 = 1; //points to the beginning of the second sublist
	//pointer points to the first item of the first sublist
}

bool MergeSort::cycle() {
	this->clearColours();

	while (true) {
		float firstVal = 32767, secondVal = 32767; //indicates an undefined value, this is currently fine as all inputs are less than this value
		bool found = false;
		if (ptr1 < pointer + sublistSize) { //if first pointer is still in range
			found = true;
			firstVal = contents[ptr1];
		}

		if (ptr2 < length && ptr2 < pointer + 2 * sublistSize) { //if second pointer is still in range
			found = true;
			secondVal = contents[ptr2];
		}

		if (found == true) {
			if (firstVal <= secondVal) {
				colours[ptr1] = 1;
				ptr1 += 1;
				combined.push_back(firstVal);
				break;
			}
			else {
				colours[ptr2] = 1;
				ptr2 += 1;
				combined.push_back(secondVal);
				break;
			}
		}
		else {
			for (int i = 0; i < combined.size(); i++) {
				contents[pointer + i] = combined[i];
			}
			combined.clear();


			pointer += 2 * sublistSize;
			ptr1 = pointer;
			ptr2 = pointer + sublistSize;
			if (ptr2 >= length) { //set up the next iteration
				pointer = 0;
				sublistSize *= 2;
				if (sublistSize >= length) {
					return true;
				}
				ptr1 = 0;
				ptr2 = sublistSize;
			}
		}
	}
	return false;
}