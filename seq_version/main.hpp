#ifndef MAIN_HPP
#define MAIN_HPP

#include <random>
#include <vector>
#include <iostream>
#include <string>
#include "node.hpp"


using namespace std;

void set_envs(unsigned int *ngram_num, unsigned int *page_limit, unsigned int *txt_length);

vector<vector<string>> tokens_to_ngrams(vector<string> token_vec, unsigned int ngram_num, default_random_engine seed);

vector<string> random_txt_gen(Node* root, unsigned int length);

#endif