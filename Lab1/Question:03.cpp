#include <iostream>
#include <string>
using namespace std;

class MedianFinder {
	int* nums;
	int size;
	int capacity;
public:
	MedianFinder() {
		size = 0;
		capacity = 1;
		nums = new int[capacity];
	}
	~MedianFinder() {
		delete[] nums;
	}
	void addNum(int num) {

		if (size == capacity) {
			int* temp = new int[capacity * 2];
			capacity = capacity * 2;
			for (int i = 0;i < size;i++) {
				temp[i] = nums[i];
			}
			delete[] nums;

			nums = temp;
		}
		int i = size - 1;
		while (i > 0 && nums[i] > num) {
			nums[i + 1] = nums[i];
			i--;
		}
		nums[i + 1] = num;
		size++;
	}
	double findMedian() {
		if (size % 2 == 0) {
			return (nums[(size / 2) - 1] + nums[size / 2]) / 2.0;
		}
		else {
			return nums[size / 2];
		}
	}
};
int main() {
	MedianFinder m;
	m.addNum(1);
	m.addNum(2);
	cout << "The median is :" << m.findMedian() << endl;
	m.addNum(3);
	cout << "The median is :" << m.findMedian() << endl;
	return 0;
}
