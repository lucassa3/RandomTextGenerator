#include <string>
#include <vector>
#include "node.hpp"

using namespace std;

Node::Node() {
  this->count = 1;
}


Node::~Node(void) {
    
}

void Node::set_child(string word, Node *node) {
    children[word] = node;
}