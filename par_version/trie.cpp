#include <vector>
#include <string>
#include <iostream>
#include "trie.hpp"
#include "node.hpp"

Node* build_trie(vector<string> ngram_vec, int ngram_size) {
    Node* root = new Node();
    
    for(int i = 0; i < ngram_vec.size() - ngram_size; i += ngram_size) {
        vector<string> ngram;
        for(unsigned int j = 0; j < ngram_size; j++) {
            ngram.push_back(ngram_vec[i+j]);
        }

        vector<Node*> aux;
        aux.push_back(root);
        for(unsigned int j = 0; j < ngram_size; j++) {
            
            if (aux[j]->children.find(ngram[j]) == aux[j]->children.end() ) {
                Node* node = new Node();
  
                aux[j]->set_child(ngram[j], node);
                aux.push_back(node);

            } else {
                aux[j]->children[ngram[j]]->count += 1;
                aux.push_back(aux[j]->children[ngram[j]]);
            }
        }      
    }

    return root;
}