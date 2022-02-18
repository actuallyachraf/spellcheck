# How to write a spellcheck function in C++

This is a C++ port of [Norvig spellcheck program in Python](http://norvig.com/spell-correct.html).

## Usage

You will need [Bazel](https://bazel.build), *Bazel* is a great build tool for Go, C++ and Java projects.
Then simply run the `run` command in *Bazel* to build and run the `main` code in the project.

```sh

$ bazel run spellecheck:spellcheck-demo

```

```cpp

#include "spellcheck.h"

int main() {

    auto suggestions = spellcheck("hllo");
    
    for (auto& sugg: suggestions) {
        std::cout << sugg << '\n';
    }

}

```