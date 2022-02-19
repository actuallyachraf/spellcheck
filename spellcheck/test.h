#ifndef LIB_TEST_H
#define LIB_TEST_H

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
void ASSERT_VECTOR_EQUALS(std::vector<std::string> got,
                          std::vector<std::string> expected) {
  assert(got.size() == expected.size());

  std::sort(got.begin(), got.end());
  std::sort(expected.begin(), expected.end());
  for (size_t i = 0; i < got.size(); i++) {
    assert(got.at(i) == expected.at(i));
  }
}

#endif