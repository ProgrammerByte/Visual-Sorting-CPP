//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include "Graphics2D.h"
#include "BubbleSort.h"
#include "BogoSort.h"
#include "ShuttleSort.h"
#include "ShakerSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "Algorithm.h"

#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int mode = 0;
int speed = 1; //number of visible operations to do every frame. Must be > 0
int length = 192;
vector<float> values; //input values
Algorithm* algorithm;
string sorts[] = { "BUBBLE", "SHUTTLE", "SHAKER", "MERGE", "QUICK", "RADIX", "BOGO" };

bool hasStarted = false;
bool showSolution = false;

Graphics2D engine = Graphics2D(1920, 1080, "Visual Sorting", true);

vector<float> xCoords; //of bars

float aspectRatio;
float barWidth;

void shuffle() {
	srand(time(0));
	for (int i = 0; i < length; i++) {
		values[i] = (float)rand() / RAND_MAX;
	}
}

void calculateXCoords() {
	xCoords.clear();
	barWidth = (float)(aspectRatio * 2) / length;
	for (int i = 0; i < length; i++) {
		xCoords.push_back((barWidth * i) - aspectRatio);
	}
	barWidth *= 0.8;
}

void resetAlgorithm(int val) {
	switch (val) {
		case 0:
			algorithm = new BubbleSort(values, length);
			break;

		case 1:
			algorithm = new ShuttleSort(values, length);
			break;

		case 2:
			algorithm = new ShakerSort(values, length);
			break;

		case 3:
			algorithm = new MergeSort(values, length);
			break;

		case 4:
			algorithm = new QuickSort(values, length);
			break;

		case 5:
			algorithm = new RadixSort(values, length);
			break;

		case 6:
			algorithm = new BogoSort(values, length);
			break;
	}
}

void globalInput(int key) { //can be called at any time
	if (key >= '1' && key <= '7') {
		mode = key - '1';
	}
	else {
		switch (key) {
			case GLFW_KEY_BACKSPACE:
				hasStarted = false;
				showSolution = false;
				break;

			case 'R':
				hasStarted = false;
				showSolution = false;
				shuffle();
				resetAlgorithm(mode);
				break;

			case GLFW_KEY_ENTER:
				hasStarted = true;
				showSolution = false;
				resetAlgorithm(mode);
				break;

			case GLFW_KEY_ESCAPE:
				engine.closeWindow();
				break;

			case GLFW_KEY_UP:
				speed += 1;
				break;

			case GLFW_KEY_DOWN:
				if (speed > 1) {
					speed -= 1;
				}
				break;

			default:
				break;
		}
	}
}

void input(int key) { //True implies start again, This code will only be executed if nothing is running
	switch (key) {
		case GLFW_KEY_RIGHT:
			if (length < 1920) {
				length += 1;
				values.push_back((float)rand() / RAND_MAX);
				calculateXCoords();
				resetAlgorithm(mode);
			}
			break;

		case GLFW_KEY_LEFT:
			if (length > 2) {
				length -= 1;
				values.pop_back();
				calculateXCoords();
				resetAlgorithm(mode);
			}
			break;

		default:
			break;
	}
}


int sizeInt(int value) {
	int count = 0;
	while (value > 0) {
		value /= 10;
		count += 1;
	}
	return count;
}


float colours[3][3] = { {1, 1, 1}, {1, 0, 0}, {0, 1, 0} };
//for now the coordinates system goes from (-aspectRatio, -1) to (aspectRatio, 1)
int main() {
	vector<int> barColours;
	int index;

	for (int i = 0; i < length; i++) {
		values.push_back(0);
	}
	shuffle();


	aspectRatio = engine.getAspectRatio();
	calculateXCoords();
	algorithm = new BubbleSort(values, length);
	engine.resizeText(0.08);

	while (engine.shouldClose() == false) {
		globalInput(engine.getCurrentKey());

		engine.renderString(-aspectRatio + 0.01, 0.8, (char*)sorts[mode].c_str(), sorts[mode].length());
		engine.renderString(aspectRatio - 1.1, 0.8, (char*)"SPEED", 5);
		engine.renderString(aspectRatio - 0.5, 0.8, (char*)to_string(speed).c_str(), sizeInt(speed));

		if (hasStarted == true) {
			for (int z = 0; z < speed; z++) {
				if (algorithm->cycle() == true) {
					hasStarted = false;
					showSolution = true;
					break;
				}
			}
		}
		else if (showSolution == true) {
			switch (algorithm->checkSolution()) {
				case -1:
					showSolution = false;
					hasStarted = true;
					break;

				case 0:
					break;

				case 1:
					showSolution = false;
					hasStarted = false;
					break;
			}
		}

		else {
			input(engine.getCurrentKey());
		}

		for (int i = 0; i < length; i++) {
			values = algorithm->getContents();
			barColours = algorithm->getColours();
			index = barColours[i];
			engine.setFillColour(colours[index][0], colours[index][1], colours[index][2], 1);
			engine.rect(xCoords[i], -1, barWidth, values[i] * 1.75);
		}

		engine.clear();
	}
}