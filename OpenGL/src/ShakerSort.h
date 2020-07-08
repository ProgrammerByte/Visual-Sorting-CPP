#include "Algorithm.h"

#pragma once

class ShakerSort : public Algorithm { //inherits from the Algorithm superClass
private:
	int iterations;
	int maxIterations;
	bool hasSwapped;
	bool moveRight;
	
	void swap(int ind1, int ind2);

public:
	ShakerSort(vector<float>& contents, int length);
	virtual bool cycle();
	~ShakerSort() {};
};