#include <vector>
#include <iostream>
#include <string>
#include "boost/tokenizer.hpp"
#include "pugixml.hpp"
#include "xml_parse.hpp"

using namespace std;

typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

vector<string> xml_to_text(const char *filename, int page_limit) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename);

    if(!result) {
        cout << "Error opening the xml file. Aborting";
        exit(EXIT_ERROR);
    }

    pugi::xml_node root_node = doc.child("mediawiki");
    vector<string> txt_vec;

    int count = 0;
    for (pugi::xml_node child_node: root_node.children("page")) {
        if(count < page_limit) {
            string node_txt = child_node.child("revision").child_value("text");
            txt_vec.push_back(node_txt);
        }
        else {break;}
        count++;
        
    }

    return txt_vec;
}

bool is_punct(char c){
    return c == '.' || c == ',' || c == '!' || c == '?';
}

bool is_alpha(char c){ 
    
    return !isalpha(c) && !is_punct(c);
}



vector<string> tokenize_text(vector<string> txt_vec) {
    vector<string> res;
    
    for(string txt: txt_vec) {
        transform(txt.begin(), txt.end(), txt.begin(), ::tolower);
        
        replace_if(txt.begin(), txt.end(), is_alpha, ' ');

        tokenizer tok{txt};
        
        vector<string> temp_str;
        
        for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
            temp_str.push_back(*it);
        
        
        res.insert(res.end(), temp_str.begin(), temp_str.end());
    }

    return res;
}