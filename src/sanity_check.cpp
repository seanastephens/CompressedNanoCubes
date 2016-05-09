#include <iostream>
#include <vector>

#include "ArrayBackedNanoCube.h"

using namespace std;

int main() {
	vector<vector<vector<bool>>> data = {
		{ { 1, 1 } , { 1, 0 } },
		{ { 1, 1 } , { 1, 1 } },
		{ { 1, 0 } , { 0, 0 } },
		{ { 1, 0 } , { 1, 1 } },
		{ { 0, 0 } , { 1, 0 } },
	};

	ArrayBackedNanoCube a(2);
	for(auto d : data)
		a.add(d, 1);

	vector<vector<bool>> query = { { 1, 1 }, { 1, 0} };
	int summary = a.summary(query);

	if(summary != 1) {
		cout << summary << " should be 1" << endl;
		return 1;
	} else {
		return 0;
	}
}
