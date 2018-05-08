#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>
#include <iostream>
#include "node.hpp"

using namespace std;

Node* build_trie(vector<vector<string>> ngram_vec);

#endif