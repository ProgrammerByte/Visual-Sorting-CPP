#include "Algorithm.h"

#pragma once

class BogoSort : public Algorithm { //inherits from the Algorithm superClass
	public:
		BogoSort(vector<float>& contents, int length);
		virtual bool cycle();
		~BogoSort() {};
};