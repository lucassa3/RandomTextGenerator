#ifndef MAIN_HPP
#define MAIN_HPP

#include <random>
#include <vector>
#include <iostream>
#include <string>
#include "node.hpp"
#include <boost/mpi.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

using namespace std;

namespace mpi = boost::mpi;

void set_envs(unsigned int *ngram_num, unsigned int *page_limit, unsigned int *txt_length);

vector<string> tokens_to_serial_ngrams(vector<string> token_vec, unsigned int ngram_num, default_random_engine seed);

vector<string> random_txt_gen(Node* root, unsigned int length, mpi::communicator world, unsigned int ngram_num);

#endif