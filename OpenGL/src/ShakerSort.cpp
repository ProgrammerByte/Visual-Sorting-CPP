#include "ShakerSort.h"

ShakerSort::ShakerSort(vector<float>& contents, int length) :Algorithm(contents, length) {
	this->iterations = 1;
	this->maxIterations = (int)(length / 2);
	this->hasSwapped = false;
	this->moveRight = true;
}

void ShakerSort::swap(int ind1, int ind2) { //TODO - MAYBE MOVE THIS TO ALGORITHM CLASS
	float tempVal = contents[ind1];
	contents[ind1] = contents[ind2];
	contents[ind2] = tempVal;
	colours[ind1] = 1;
	colours[ind2] = 1;
	hasSwapped = true;
}

bool ShakerSort::cycle() {
	this->clearColours();
	
	while (true) {
		if (moveRight == true) {
			if (pointer < length - iterations) {
				if (contents[pointer] > contents[pointer + 1]) {
					swap(pointer, pointer + 1);
				}
				pointer += 1;
				break;
			}
			else { //changeDirection
				moveRight = false;
				hasSwapped = false;
			}
		}

		else {
			if (pointer >= iterations) {
				if (contents[pointer] < contents[pointer - 1]) {
					swap(pointer, pointer - 1);
				}
				pointer -= 1;
				break;
			}
			else {
				if (iterations == maxIterations || hasSwapped == false) {
					pointer = 0;
					return true;
				}
				iterations += 1;
				moveRight = true;
				hasSwapped = false;
			}
		}
	}
	return false;
}