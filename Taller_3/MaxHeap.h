#pragma once
#include <vector>
using namespace std;
class MaxHeap

{
private:
	vector<float> heap;

	void turnIntoMaxHeap(int index);

	void Swap(float& a, float& b);

public:
	MaxHeap();

	void insert(float value);

	void printHeap();


};
