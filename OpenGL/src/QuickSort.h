#include "Algorithm.h"

#pragma once

class QuickSort : public Algorithm { //inherits from the Algorithm superClass
	private:
		//bool nonPivot;
		int currentPivot;
		vector<bool> pivots;

	public:
		QuickSort(vector<float>& contents, int length);
		virtual bool cycle();
		~QuickSort() {};
};
