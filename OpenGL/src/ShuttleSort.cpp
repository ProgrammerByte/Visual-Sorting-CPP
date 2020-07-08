#include "ShuttleSort.h"

ShuttleSort::ShuttleSort(vector<float>& contents, int length) :Algorithm(contents, length) {
	this->iterations = 0;
	this->pointer = 1;
}

bool ShuttleSort::cycle() {
	this->clearColours();

	while (true) {
		if (pointer > 0) {
			if (contents[pointer] < contents[pointer - 1]) {
				float tempVal = contents[pointer];
				contents[pointer] = contents[pointer - 1];
				contents[pointer - 1] = tempVal;
				pointer -= 1;
				colours[pointer] = 1;
				colours[pointer - 1] = 1;
				break;
			}
		}
		if (iterations >= length - 2) {
			pointer = 0;
			return true;
		}
		iterations += 1;
		pointer = iterations + 1;
	}
	return false;
}