#pragma once

#include <vector>
#include <cstdbool>
#include <cstdint>

using namespace std;

class ArrayBackedNanoCube {

public:
	ArrayBackedNanoCube(size_t num_dimensions);
	void add(vector<vector<bool>> path, uint32_t value);
	uint32_t summary(vector<vector<bool>> path);

private:
	const size_t num_dimensions;
	// vector<ArrayStore> arrays;
	// ReferenceCountedTable summaries;
};
