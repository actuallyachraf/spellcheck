#ifndef LIB_SPELL_CHECK_H
#define LIB_SPELL_CHECK_H
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
typedef std::map<std::string, int> Dict;

std::string spellcheck(std::string text, Dict dict);
std::vector<std::pair<std::string, std::string>> countSplits(std::string word);
double wordProba(std::string word, Dict dict);
std::vector<std::string> genCandidates(std::string word, Dict dict);
std::vector<std::string> countDeletes(
    std::vector<std::pair<std::string, std::string>> splits);
std::vector<std::string> countTransposes(
    std::vector<std::pair<std::string, std::string>> splits);
std::vector<std::string> countReplaces(
    std::vector<std::pair<std::string, std::string>> splits);
std::vector<std::string> countInserts(
    std::vector<std::pair<std::string, std::string>> splits);

std::vector<std::string> countEdits(std::string word);
std::map<std::string, int> lazyReadWords(std::string filename);
void countWords(std::vector<std::string> words);
#endif