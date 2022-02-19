# How to write a spellcheck function in C++

This is a C++ port of [Norvig spellcheck program in Python](http://norvig.com/spell-correct.html).

## Usage

You will need [Bazel](https://bazel.build), _Bazel_ is a great build tool for Go, C++ and Java projects.
Then simply run the `run` command in _Bazel_ to build and run the `main` code in the project.

```sh

$ bazel run spellecheck:spellcheck-demo

```

```cpp

#include "spellcheck.h"

const WORDS_FILE_PATH = "/path/to/a/dict";

int main() {

    auto myDict = lazyReadWords(WORDS_FILE_PATH);
    auto suggestions = spellcheck("hllo");

    for (auto& sugg: suggestions) {
        std::cout << sugg << '\n';
    }

}

```

## How does it work ?

The spellchecker core algorithm is essentially the maximum likelihood of the distance between
an input and possible alterations of the input.

For each word in a corpus we run several corruptions such as removing, transposing or adding more characters.
By iterating over the possible corrupted words we choose the one that is closest to the original spelling
by comparing the word's probability (how many times it appears in the corpus divided by the corpus size)
and returning the best candidate.
