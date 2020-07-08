#include "RadixSort.h"

RadixSort::RadixSort(vector<float>& contents, int length) :Algorithm(contents, length) {
	currentDigit = 1000000; //looks at 6 digits after the decimal point (amount needed for float)

	for (int i = 0; i < length; i++) { //initialises the digits array
		digits.push_back((int)((int)(contents[i] * currentDigit)) % 10); //least significant digit
		nextList.push_back(0);
	}

	for (int i = 0; i < 10; i++) {
		counts[i] = 0; //counts[0] will always be 0 (until solution)
	}
}

bool RadixSort::cycle() {
	this->clearColours();

	if (pointer < length) {
		int val = digits[pointer];
		if (val != 9) {
			counts[val + 1] += 1; //shifted over to indicate start position
		}

		colours[pointer] = 1;
		pointer += 1;
	}

	else { //apply results
		for (int i = 1; i < 10; i++) { //converts to a list of positions for the next item for any given digit
			counts[i] += counts[i - 1];
		}

		for (int i = 0; i < length; i++) {
			nextList[counts[digits[i]]] = contents[i]; //uses positions (counts) array to determine new position
			counts[digits[i]] += 1;
		}
		
		for (int i = 0; i < length; i++) {
			contents[i] = nextList[i]; //copies new array to the current contents
		}

		pointer = 0;
		if (currentDigit == 10) {
			return true;
		}

		currentDigit *= 0.1;
		for (int i = 0; i < length; i++) { //determines new digits array
			digits[i] = (int)((int)(contents[i] * currentDigit)) % 10;
		}

		for (int i = 0; i < 10; i++) { //reset counts array
			counts[i] = 0;
		}
	}


	return false;
}