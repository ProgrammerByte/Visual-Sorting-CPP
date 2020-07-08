#include "Algorithm.h" //The base class for the sorting algorithms

Algorithm::Algorithm(vector<float> &contents, int length) {
	this->contents = contents; //TODO - THIS MIGHT NOT WORK AS EXPECTED
	this->length = length;
	this->pointer = 0;

	for (int i = 0; i < length; i++) {
		this->colours.push_back(0); //initialises all bars as white, 0 = white, 1 = red, 2 = green
	}
}

bool Algorithm::cycle() { //has finished?
	return false;
}

int Algorithm::checkSolution() { //1 = verification succeeded, 0 = not finished, -1 = verification failed
	if (pointer < length - 1) { //assuming that the pointer starts at 0
		if (contents[pointer] <= contents[pointer + 1]) {
			colours[pointer] = 2;
			pointer += 1;
			return 0;
		}

		pointer = 0;
		clearColours();
		return -1;
	}
	colours[pointer] = 2;
	pointer = 0;
	return 1; //pointer has reached the end, therefore verification has been successful
}

void Algorithm::clearColours() {
	for (int i = 0; i < length; i++) {
		colours[i] = 0;
	}
}

vector<float> Algorithm::getContents() {
	return contents;
}

vector<int> Algorithm::getColours() {
	return colours;
}