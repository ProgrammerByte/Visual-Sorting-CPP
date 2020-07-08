#include "Algorithm.h"

#pragma once

class MergeSort : public Algorithm { //inherits from the Algorithm superClass
private:
	//int iterations;
	//bool hasSwapped;
	int sublistSize;
	int ptr1;
	int ptr2;
	vector<float>combined; //combined two sublists

public:
	MergeSort(vector<float>& contents, int length);
	virtual bool cycle();
	~MergeSort() {};
};
