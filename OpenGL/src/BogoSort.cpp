#include "BogoSort.h"

#include <time.h>

BogoSort::BogoSort(vector<float>& contents, int length) : Algorithm(contents, length) {
	srand(time(0));
}

bool BogoSort::cycle() {
	int chosenIndex;
	vector<float> result;
	for (int i = 0; i < length; i++) {
		chosenIndex = (rand() * (length - i)) / RAND_MAX;
		if (chosenIndex == length - i) { //if out of range due to computational error
			chosenIndex -= 1;
		}
		result.push_back(contents[chosenIndex]);
		contents.erase(contents.begin() + chosenIndex);
	}
	contents = result;
	return true;
}