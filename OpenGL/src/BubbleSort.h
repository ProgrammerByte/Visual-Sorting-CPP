#include "Algorithm.h"

#pragma once

class BubbleSort : public Algorithm { //inherits from the Algorithm superClass
	private:
		int iterations;
		bool hasSwapped;

	public:
		BubbleSort(vector<float> &contents, int length);
		bool cycle();
		~BubbleSort() {};
};
	