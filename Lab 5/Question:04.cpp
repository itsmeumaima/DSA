#include <iostream>
#include <algorithm>
using namespace std;

class Umaima_Lab05 {
	int n;
	int* arr;
public:
	Umaima_Lab05(int no) {
		n = no;
		arr = new int[n];
	}
	~Umaima_Lab05() {
		delete[] arr;
	}
	void inputdata() {
		cout << "Enter the data for harmonious array:" << endl;
		for (int i = 0; i < n; i++) {
			cout << "Enter data :";
			cin >> arr[i];
		}
	}
    int long_subsequence() {
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        int freq[101] = { 0 };
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        int maxLength = 0;
        for (int i = 1; i < maxVal; i++) { 
            if (freq[i] > 0 && freq[i + 1] > 0) {
                int length = freq[i] + freq[i + 1];
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
        return maxLength;
    }
};

int main() {
	int no;
	cout << "Enter the length of harmonious array:";
	cin >> no;
	Umaima_Lab05 harmonious_seq(no);
	harmonious_seq.inputdata();
	int ans=harmonious_seq.long_subsequence();
	cout << "The length of the longest harmonious substring is :" << ans;
	return 0;
}
