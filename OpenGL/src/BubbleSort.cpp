#include "BubbleSort.h"

BubbleSort::BubbleSort(vector<float> &contents, int length):Algorithm(contents, length) {
	this->iterations = 0;
	this->hasSwapped = false;
}

bool BubbleSort::cycle() {
	this->clearColours();

	while (true) {
		if (pointer < length - (1 + iterations)) {
			if (contents[pointer] > contents[pointer + 1]) {
				float temp = contents[pointer]; //swaps two contents
				contents[pointer] = contents[pointer + 1];
				contents[pointer + 1] = temp;
				hasSwapped = true;

				colours[pointer] = 1; //changes colour to red - TODO create a colour change method in the future bar class
				colours[pointer + 1] = 1;

				pointer += 1;
				break;
			}
			pointer += 1;
		}
		else {
			pointer = 0;
			iterations += 1;
			if (iterations == length || hasSwapped == false) {
				return true;
			}
			hasSwapped = false;
		}
	}
	return false;
}