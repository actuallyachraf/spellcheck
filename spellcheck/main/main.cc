#include <iostream>

#include "../spell-check.h"
#include "../test.h"

int main() {
  std::string text =
      "Some people, when confronted with a problem, think "
      "\"I know, I'll use regular expressions.\" "
      "Now they have two problems.";
  auto words = spellcheck(text);

  auto splits = countSplits("hello");
  auto deletes = countDeletes(splits);
  auto transposes = countTransposes(splits);
  auto replaces = countReplaces(splits);
  auto inserts = countInserts(splits);

  auto edits = countEdits("hello");

  std::vector<std::string> EXPECTED_TRANSPOSES{"ehllo", "hlelo", "hello",
                                               "helol"};

  std::vector<std::string> EXPECTED_DELETES{"ello", "hllo", "helo", "helo",
                                            "hell"};
  std::vector<std::string> EXPECTED_REPLACES{
      "aello", "bello", "cello", "dello", "eello", "fello", "gello", "hello",
      "iello", "jello", "kello", "lello", "mello", "nello", "oello", "pello",
      "qello", "rello", "sello", "tello", "uello", "vello", "wello", "xello",
      "yello", "zello", "hallo", "hbllo", "hcllo", "hdllo", "hello", "hfllo",
      "hgllo", "hhllo", "hillo", "hjllo", "hkllo", "hlllo", "hmllo", "hnllo",
      "hollo", "hpllo", "hqllo", "hrllo", "hsllo", "htllo", "hullo", "hvllo",
      "hwllo", "hxllo", "hyllo", "hzllo", "healo", "heblo", "heclo", "hedlo",
      "heelo", "heflo", "heglo", "hehlo", "heilo", "hejlo", "heklo", "hello",
      "hemlo", "henlo", "heolo", "heplo", "heqlo", "herlo", "heslo", "hetlo",
      "heulo", "hevlo", "hewlo", "hexlo", "heylo", "hezlo", "helao", "helbo",
      "helco", "heldo", "heleo", "helfo", "helgo", "helho", "helio", "heljo",
      "helko", "hello", "helmo", "helno", "heloo", "helpo", "helqo", "helro",
      "helso", "helto", "heluo", "helvo", "helwo", "helxo", "helyo", "helzo",
      "hella", "hellb", "hellc", "helld", "helle", "hellf", "hellg", "hellh",
      "helli", "hellj", "hellk", "helll", "hellm", "helln", "hello", "hellp",
      "hellq", "hellr", "hells", "hellt", "hellu", "hellv", "hellw", "hellx",
      "helly", "hellz"};

  std::vector<std::string> EXPECTED_INSERTS{
      "ahello", "bhello", "chello", "dhello", "ehello", "fhello", "ghello",
      "hhello", "ihello", "jhello", "khello", "lhello", "mhello", "nhello",
      "ohello", "phello", "qhello", "rhello", "shello", "thello", "uhello",
      "vhello", "whello", "xhello", "yhello", "zhello", "haello", "hbello",
      "hcello", "hdello", "heello", "hfello", "hgello", "hhello", "hiello",
      "hjello", "hkello", "hlello", "hmello", "hnello", "hoello", "hpello",
      "hqello", "hrello", "hsello", "htello", "huello", "hvello", "hwello",
      "hxello", "hyello", "hzello", "heallo", "hebllo", "hecllo", "hedllo",
      "heello", "hefllo", "hegllo", "hehllo", "heillo", "hejllo", "hekllo",
      "helllo", "hemllo", "henllo", "heollo", "hepllo", "heqllo", "herllo",
      "hesllo", "hetllo", "heullo", "hevllo", "hewllo", "hexllo", "heyllo",
      "hezllo", "helalo", "helblo", "helclo", "heldlo", "helelo", "helflo",
      "helglo", "helhlo", "helilo", "heljlo", "helklo", "helllo", "helmlo",
      "helnlo", "helolo", "helplo", "helqlo", "helrlo", "helslo", "heltlo",
      "helulo", "helvlo", "helwlo", "helxlo", "helylo", "helzlo", "hellao",
      "hellbo", "hellco", "helldo", "helleo", "hellfo", "hellgo", "hellho",
      "hellio", "helljo", "hellko", "helllo", "hellmo", "hellno", "helloo",
      "hellpo", "hellqo", "hellro", "hellso", "hellto", "helluo", "hellvo",
      "hellwo", "hellxo", "hellyo", "hellzo", "helloa", "hellob", "helloc",
      "hellod", "helloe", "hellof", "hellog", "helloh", "helloi", "helloj",
      "hellok", "hellol", "hellom", "hellon", "helloo", "hellop", "helloq",
      "hellor", "hellos", "hellot", "hellou", "hellov", "hellow", "hellox",
      "helloy", "helloz"};

  std::vector<std::string> EXPECTED_EDITS{
      "heleo",  "iello",  "hzello", "helclo", "hhllo",  "hellbo", "hejlo",
      "helho",  "hpello", "hillo",  "hcello", "hezllo", "heljlo", "uhello",
      "hellog", "heldlo", "helwlo", "thello", "whello", "hellow", "ehllo",
      "hellw",  "hnllo",  "henlo",  "haello", "hellio", "hellto", "hkllo",
      "hellz",  "heqllo", "helzo",  "hedlo",  "hellq",  "hellon", "mello",
      "fhello", "hellor", "hellh",  "hellf",  "helleo", "hellx",  "helmlo",
      "hwello", "helao",  "hxllo",  "hellgo", "helalo", "hellox", "herllo",
      "bello",  "hollo",  "hehlo",  "helnlo", "hpllo",  "hejllo", "hellyo",
      "helvlo", "hgello", "helvo",  "hemllo", "hellu",  "helglo", "helldo",
      "dello",  "hjello", "hellos", "hezlo",  "shello", "vello",  "hellro",
      "helklo", "hbello", "hellm",  "hellpo", "helly",  "helqo",  "hevlo",
      "hzllo",  "heclo",  "wello",  "heluo",  "hebllo", "heloo",  "hallo",
      "hkello", "hexllo", "helxlo", "hiello", "helzlo", "hellol", "helplo",
      "hellzo", "nello",  "hellno", "dhello", "ohello", "fello",  "helno",
      "ihello", "hefllo", "helrlo", "hell",   "hewllo", "helblo", "jello",
      "helloo", "hvllo",  "heyllo", "hellou", "helll",  "htello", "hello",
      "hemlo",  "hyello", "hepllo", "helloj", "hllo",   "hevllo", "hellvo",
      "helso",  "helloi", "hellop", "hullo",  "heilo",  "hlelo",  "khello",
      "hells",  "nhello", "hdello", "hoello", "heklo",  "hlello", "helloc",
      "heqlo",  "kello",  "heldo",  "helelo", "qhello", "xhello", "qello",
      "hellco", "heillo", "hellwo", "heslo",  "helgo",  "heolo",  "hbllo",
      "helfo",  "heello", "helko",  "ello",   "sello",  "zello",  "hgllo",
      "helwo",  "huello", "hesllo", "hwllo",  "rello",  "eello",  "hfello",
      "helpo",  "heltlo", "helloy", "heplo",  "helloz", "helloq", "cello",
      "hellot", "pello",  "xello",  "hexlo",  "hella",  "ahello", "heflo",
      "helljo", "htllo",  "heljo",  "hellao", "helo",   "hxello", "helylo",
      "hellt",  "herlo",  "helto",  "helqlo", "helld",  "helln",  "hellr",
      "heelo",  "lhello", "hsello", "hedllo", "hhello", "hmello", "chello",
      "lello",  "tello",  "hcllo",  "heylo",  "ehello", "helulo", "hellmo",
      "hellof", "helloh", "hellok", "hqello", "hellv",  "helslo", "heblo",
      "uello",  "hellc",  "hellj",  "helhlo", "helmo",  "hellfo", "hellxo",
      "helllo", "helloe", "healo",  "yhello", "hekllo", "hlllo",  "helxo",
      "helflo", "hsllo",  "helolo", "helluo", "jhello", "hellko", "gello",
      "henllo", "mhello", "helilo", "hellod", "oello",  "phello", "helloa",
      "hetlo",  "hewlo",  "hdllo",  "hellb",  "vhello", "hellqo", "heulo",
      "hellho", "aello",  "rhello", "hvello", "yello",  "hellom", "hellov",
      "hrello", "hjllo",  "bhello", "hecllo", "ghello", "heallo", "hnello",
      "hyllo",  "hetllo", "hellob", "hfllo",  "helco",  "hmllo",  "helbo",
      "hegllo", "hellso", "helyo",  "zhello", "hellp",  "hehllo", "helli",
      "heollo", "helle",  "helro",  "heglo",  "helio",  "hellg",  "hqllo",
      "hrllo",  "heullo", "hellk",  "helol"};

  ASSERT_VECTOR_EQUALS(replaces, EXPECTED_REPLACES);
  ASSERT_VECTOR_EQUALS(deletes, EXPECTED_DELETES);
  ASSERT_VECTOR_EQUALS(transposes, EXPECTED_TRANSPOSES);
  ASSERT_VECTOR_EQUALS(inserts, EXPECTED_INSERTS);
  ASSERT_WORD_IN_SET(EXPECTED_EDITS, edits);
  return 0;
}