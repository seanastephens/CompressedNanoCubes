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
	cout << a.count(query) << " should be 1" << endl;
}
