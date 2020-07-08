#include "Algorithm.h"

#pragma once

class ShuttleSort : public Algorithm { //inherits from the Algorithm superClass
private:
	int iterations;

public:
	ShuttleSort(vector<float>& contents, int length);
	virtual bool cycle();
	~ShuttleSort() {};
};

