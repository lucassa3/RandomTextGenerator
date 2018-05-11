#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>
#include <iostream>
#include "node.hpp"

using namespace std;

Node* build_trie(vector<string> ngram_vec, unsigned int ngram_size);

#endif