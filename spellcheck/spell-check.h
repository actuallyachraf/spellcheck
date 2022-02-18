#ifndef LIB_SPELL_CHECK_H
#define LIB_SPELL_CHECK_H
#include <string>
#include <unordered_set>
#include <vector>

std::vector<std::string> spellcheck(std::string text);
std::vector<std::pair<std::string, std::string>> countSplits(std::string word);

std::vector<std::string> countDeletes(
    std::vector<std::pair<std::string, std::string>> splits);
std::vector<std::string> countTransposes(
    std::vector<std::pair<std::string, std::string>> splits);
std::vector<std::string> countReplaces(
    std::vector<std::pair<std::string, std::string>> splits);
std::vector<std::string> countInserts(
    std::vector<std::pair<std::string, std::string>> splits);

std::unordered_set<std::string> countEdits(std::string word);
void countWords(std::vector<std::string> words);
#endif