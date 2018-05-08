#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
    public:

    unsigned int count;
    
    map<string, Node*> children;

    Node();
    
    ~Node(void);

    void set_child(string word, Node *node);
};

#endif