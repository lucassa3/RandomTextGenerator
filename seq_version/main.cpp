#include <random>
#include <vector>
#include <iostream>
#include <string>
#include "xml_parse.hpp"
#include "trie.hpp"
#include <time.h>

#define EXIT_ERROR 1
#define NGRAM_NUM 6
#define LENGTH 10

using namespace std;

void set_envs(unsigned int *ngram_num, unsigned int *page_limit, unsigned int *txt_length) {
    
    char *ngram_num_env, *page_limit_env, *txt_length_env;

    ngram_num_env = getenv ("NGRAM_NUM");
    if(ngram_num_env != NULL) {
        *ngram_num = atoi(ngram_num_env);
    }

    page_limit_env = getenv ("PAGE_LIMIT");
    if(page_limit_env != NULL) {
        *page_limit = atoi(page_limit_env);
    }

    txt_length_env = getenv ("TXT_LENGTH");
    if(txt_length_env != NULL) {
        *txt_length = atoi(txt_length_env);
    }
}

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
    
    unsigned int ngram_num = 4;
    unsigned int page_limit = 2000;
    unsigned int txt_length = 20;
    
    vector<string> wiki_files = {"../src/wikidump01.xml", "../src/wikidump02.xml", "../src/wikidump03.xml", "../src/wikidump04.xml"};

    clock_t begin = clock();

    random_device rd;
    default_random_engine seed(rd());

    set_envs(&ngram_num, &page_limit, &txt_length);

    vector<string> txt = xml_to_text(wiki_files, page_limit);

    vector<string> txt_tokenized = tokenize_text(txt);

    vector<vector<string>> ngrams = tokens_to_ngrams(txt_tokenized, ngram_num);
    
    Node *root = build_trie(ngrams);
    
    vector<string> generated_text = random_txt_gen(root, txt_length, seed);
    
    cout << "\n";
    for(unsigned int j = 0; j< generated_text.size(); j++) {
        cout << generated_text[j] << " ";
    }
    cout << "\n\n";

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Total time elapsed: " << time_spent << " seconds" << endl;

    
    return 0;
}