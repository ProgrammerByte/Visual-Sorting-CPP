#include <vector>

#pragma once

using namespace std;

class Algorithm {
	protected:
		void clearColours();

		vector<float> contents;
		vector<int> colours;
		int length;
		int pointer;

	public:
		Algorithm(vector<float> &contents, int length);
		virtual bool cycle();
		int checkSolution();
		vector<float> getContents();
		vector<int> getColours();
		~Algorithm(){};
};