#include "spell-check.h"

#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>

const std::regex r("(\\w+)");
const std::string LETTERS{"abcdefghijklmnopqrstuvwxyz"};

std::vector<std::string> spellcheck(std::string text) {
  auto it_begin = std::sregex_iterator(text.begin(), text.end(), r);
  auto it_end = std::sregex_iterator();

  std::vector<std::string> words;
  for (auto it = it_begin; it != it_end; ++it) {
    std::smatch match = *it;
    words.push_back(match.str());
  }

  return words;
}

std::vector<std::pair<std::string, std::string>> countSplits(std::string word) {
  std::vector<std::pair<std::string, std::string>> splits;
  for (size_t i = 0; i < word.length() + 1; i++) {
    auto left_split = word.substr(0, i);
    auto right_split = word.substr(i, word.length());

    splits.push_back({left_split, right_split});
  }
  return splits;
}

std::vector<std::string> countDeletes(
    std::vector<std::pair<std::string, std::string>> splits) {
  std::vector<std::string> deletes;
  for (auto& split : splits) {
    auto L = split.first;
    auto R = split.second;
    if (!R.empty()) {
      auto w = L + R.substr(1, R.length());
      deletes.push_back(w);
    }
  }
  return deletes;
}

std::vector<std::string> countTransposes(
    std::vector<std::pair<std::string, std::string>> splits) {
  std::vector<std::string> transposes;
  for (auto& split : splits) {
    auto L = split.first;
    auto R = split.second;
    if (R.length() > 1) {
      auto w = L + R.at(1) + R.at(0) + R.substr(2, R.length());
      transposes.push_back(w);
    }
  }
  return transposes;
}

std::vector<std::string> countReplaces(
    std::vector<std::pair<std::string, std::string>> splits) {
  std::vector<std::string> replaces;
  for (auto& split : splits) {
    auto L = split.first;
    auto R = split.second;
    if (!R.empty()) {
      for (auto& c : LETTERS) {
        auto w = L + c + R.substr(1, R.length());
        replaces.push_back(w);
      }
    }
  }
  return replaces;
}
std::vector<std::string> countInserts(
    std::vector<std::pair<std::string, std::string>> splits) {
  std::vector<std::string> inserts;
  for (auto& split : splits) {
    auto L = split.first;
    auto R = split.second;
    for (auto& c : LETTERS) {
      auto w = L + c + R;
      inserts.push_back(w);
    }
  }
  return inserts;
}

std::unordered_set<std::string> countEdits(std::string word) {
  auto splits = countSplits(word);
  auto deletes = countDeletes(splits);
  auto transposes = countTransposes(splits);
  auto replaces = countReplaces(splits);
  auto inserts = countInserts(splits);

  std::vector<std::string> edits;
  edits.reserve(deletes.size() + transposes.size() + replaces.size() +
                inserts.size());

  edits.insert(edits.end(), deletes.begin(), deletes.end());
  edits.insert(edits.end(), transposes.begin(), transposes.end());
  edits.insert(edits.end(), replaces.begin(), replaces.end());
  edits.insert(edits.end(), inserts.begin(), inserts.end());

  std::unordered_set<std::string> allEdits(edits.begin(), edits.end());
  return allEdits;
}

std::map<std::string, int> Counter(std::vector<std::string> words) {
  std::map<std::string, int> counter;

  for (auto& word : words) {
    counter[word]++;
  }
  return counter;
}
void countWords(std::vector<std::string> words) {
  auto count = Counter(words);
  std::cout << "WORD  "
            << "COUNT" << '\n';
  for (auto [k, v] : count) {
    std::cout << k << "  " << v << '\n';
  }
}
