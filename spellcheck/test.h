#ifndef LIB_TEST_H
#define LIB_TEST_H

#include <cassert>
#include <string>
#include <unordered_set>
#include <vector>

void ASSERT_VECTOR_EQUALS(std::vector<std::string> got,
                          std::vector<std::string> expected) {
  assert(got.size() == expected.size());

  for (size_t i = 0; i < got.size(); i++) {
    assert(got.at(i) == expected.at(i));
  }
}

void ASSERT_WORD_IN_SET(std::vector<std::string> words,
                        std::unordered_set<std::string> wordSet) {
  for (auto& word : words) {
    assert(wordSet.count(word) == 1);
  }
}

#endif