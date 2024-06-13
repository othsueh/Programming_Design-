#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> x(5);  // we'll be using 1-indexing
	vector<int> y(5);
	for (int i = 1; i <= 4; i++) { cin >> x[i] >> y[i]; }

	// Case 1
	if (x[4] >= x[2] && x[3] <= x[1] && y[4] >= y[2] && y[3] <= y[1]) {
		cout << 0;
	}
	// Case 2
	else if (x[3] <= x[1] && y[3] <= y[1] && y[4] > y[1] && x[4] >= x[2]) {
		cout << (x[2] - x[1]) * (y[2] - y[4]);
	}
	// Case 3
	else if (y[3] < y[2] && x[3] <= x[1] && y[4] >= y[2] && x[4] >= x[2]) {
		cout << (x[2] - x[1]) * (y[3] - y[1]);
	}
	// Case 4
	else if (x[4] > x[1] && x[3] <= x[1] && y[4] >= y[2] && y[3] <= y[1]) {
		cout << (x[2] - x[4]) * (y[2] - y[1]);
	}
	// Case 5
	else if (x[3] < x[2] && x[4] >= x[2] && y[4] >= y[2] && y[3] <= x[1]) {
		cout << (x[3] - x[1]) * (y[2] - y[1]);
	}
	// Case 6 and the corner case
	else {
		cout << (x[2] - x[1]) * (y[2] - y[1]);
	}
}
