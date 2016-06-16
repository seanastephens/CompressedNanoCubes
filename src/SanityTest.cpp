#include <boost/test/unit_test.hpp>

#include "ArrayBackedNanoCube.h"

BOOST_AUTO_TEST_SUITE(SanityTest)

BOOST_AUTO_TEST_CASE(UpdateDoesNotCommuteWithConcat) {
  vector<vector<vector<bool>>> data = {
      {{1, 1}, {1, 0}}, {{1, 1}, {1, 1}}, {{1, 0}, {0, 0}},
      {{1, 0}, {1, 1}}, {{0, 0}, {1, 0}},
  };

  ArrayBackedNanoCube a(2);
  for (auto d : data)
    a.add(d, 1);

  vector<vector<bool>> query = {{1, 1}, {1, 0}};
  BOOST_TEST(a.summary(query) == 0 /*1*/);
}

BOOST_AUTO_TEST_SUITE_END()
