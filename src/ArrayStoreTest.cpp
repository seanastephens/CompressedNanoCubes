#include <boost/test/unit_test.hpp>

#include "ArrayStore.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ArrayStoreTest)

BOOST_AUTO_TEST_CASE(AllocatesMemory) {
  ArrayStore<int> a;
  auto i = a.alloc();
  a[i] = 1;
  BOOST_TEST(a[i] == 1);
}

BOOST_AUTO_TEST_CASE(AllocatesManyElements) {
  ArrayStore<int> a;
  vector<size_t> indices;

  size_t count = 0;
  while (count++ < 10)
    indices.push_back(a.alloc());

  for (auto i : indices)
    a[i] = i;

  for (auto i : indices)
    BOOST_TEST(a[i] == i);
}

BOOST_AUTO_TEST_CASE(SizeMatches) {
  ArrayStore<int> a;
  vector<size_t> indices;

  for (int i = 0; i < 10; i++) {
    indices.push_back(a.alloc());
    BOOST_TEST(a.size() == i + 1);
  }

  for (int i = 10 - 1; i >= 0; i--) {
    a.free(indices.at(i));
    BOOST_TEST(a.size() == i);
  }
}

BOOST_AUTO_TEST_CASE(CapacityRemainsLow) {
  ArrayStore<int> a;

  for (int i = 0; i < 10; i++) {
    vector<size_t> indices;
    for (int i = 0; i < 10; i++)
      indices.push_back(a.alloc());

    for (auto i : indices)
      a.free(i);
  }

  BOOST_TEST(a.capacity() == 10);
}

BOOST_AUTO_TEST_CASE(FuzzTest) {
  ArrayStore<int> a;

  vector<int> indices;
  for (int i = 0; i < 1000; i++)
    indices.push_back(a.alloc());

  // TODO
}

BOOST_AUTO_TEST_SUITE_END()
