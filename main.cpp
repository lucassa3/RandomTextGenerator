#include <random>
#include <vector>
#include <iostream>
#include <string>
#include "xml_parse.hpp"
#include "trie.hpp"

#define EXIT_ERROR 1
#define NGRAM_NUM 6
#define LENGTH 10

using namespace std;

vector<vector<string>> tokens_to_ngrams(vector<string> token_vec, unsigned int ngram_num) {
    
    vector<vector<string>> ngram_vec;

    for (unsigned int i = 0; i <= token_vec.size() - ngram_num; i++) {
        vector<string> ngram;

        for(unsigned int j = 0; j<ngram_num; j++) {
            ngram.push_back(token_vec[i+j]);
        }

        ngram_vec.push_back(ngram);
    }

    return ngram_vec;
}

vector<string> random_txt_gen(Node* root, unsigned int length, default_random_engine seed) {
    
    Node* curr = root;
    vector<string> text;

    for(unsigned int j = 0; j < length; j++) {
        
        if(!text.empty()) {
            curr = root->children[text.back()];
        }

        while (!curr->children.empty()) {
            vector<string> word_vec;
            vector<int> count_vec;
                
            for(auto it = curr->children.begin(); it != curr->children.end(); ++it) {
                count_vec.push_back(it->second->count);
                word_vec.push_back(it->first);
            }

            discrete_distribution<int> distribute(count_vec.begin(), count_vec.end());

            auto idx = distribute(seed);

            text.push_back(word_vec[idx]);

            curr = curr->children[word_vec[idx]];
        }
    }

    return text;  
}

int main(int argc, char *argv[]) {  
    
    const char *filename = argv[1];

    random_device rd;
    default_random_engine seed(rd());

    vector<string> txt = xml_to_text(filename);

    vector<string> txt_tokenized = tokenize_text(txt);

    vector<vector<string>> ngrams = tokens_to_ngrams(txt_tokenized, NGRAM_NUM);
    
    Node *root = build_trie(ngrams);
    
    vector<string> generated_text = random_txt_gen(root, LENGTH, seed);
    
    for(unsigned int j = 0; j< generated_text.size(); j++) {
        cout << generated_text[j] << " ";
    }
    
    return 0;
}