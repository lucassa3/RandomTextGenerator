#include <vector>
#include <string>
#include <iostream>
#include "trie.hpp"
#include "node.hpp"

Node* build_trie(vector<vector<string>> ngram_vec) {
    Node* root = new Node();
    
    for(vector<string> ngram: ngram_vec) {
        vector<Node*> aux;
        aux.push_back(root);
        for(unsigned int i = 0; i < ngram.size(); i++) {
            
            if (aux[i]->children.find(ngram[i]) == aux[i]->children.end() ) {
                Node* node = new Node();
  
                aux[i]->set_child(ngram[i], node);
                aux.push_back(node);

            } else {
                aux[i]->children[ngram[i]]->count += 1;
                aux.push_back(aux[i]->children[ngram[i]]);
            }
        }      
    }

    return root;
}