#include "Algorithm.h"

#pragma once

class RadixSort : public Algorithm { //inherits from the Algorithm superClass
private:
	vector<int> digits; //stores all current digits in use
	vector<float> nextList; //USING LOTS OF EXTRA SPACE
	int counts[10]; //shifted over and eventually summed all previous elements, hence giving position in list
	int currentDigit;

public:
	RadixSort(vector<float>& contents, int length);
	virtual bool cycle();
	~RadixSort() {};
};
