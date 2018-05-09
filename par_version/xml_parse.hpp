#ifndef XML_PARSE_HPP
#define XML_PARSE_HPP

#include <string>
#include <vector>

#define EXIT_ERROR 1

using namespace std;

vector<string> xml_to_text(const char *filename, int page_limit);

bool is_alpha(char c);

vector<string> tokenize_text(vector<string> txt_vec);

#endif