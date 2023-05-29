#include "parser.hpp"
#include <cstring>

using namespace nwr;

string nextToken(string* str) {
    string val = "";

    *str = str->substr(str->find_first_not_of(' '));

    char c = str->front();

    if(str->substr(1).empty()) {
        val += c;
        *str = str->substr(1);
        return val;
    }

    while((isalpha(c) || c == '_') || (!val.empty() && isdigit(c))) {
        val += c;
        *str = str->substr(1);
        c = str->front();
    }
    if(val.empty()) {
        while(!str->empty() && (isdigit(c) || c == '.')) {
            val += c;
            *str = str->substr(1);
            c = str->front();
        }
        if(val.empty()) {

#define L2C1(i, j)\
case(i): {\
if(str->at(1) == j) {\
val+=c;\
*str = str->substr(1);\
c = str->front();\
}\
} break;
#define L2C2(i, j, k)\
case(i): {\
if(str->at(1) == j || str->at(1) == k) {\
val+=c;\
*str = str->substr(1);\
c = str->front();\
}\
} break;
#define L2C3(i, j, k, l)\
case(i): {\
if(str->at(1) == j || str->at(1) == k || str->at(1) == l) {\
val+=c;\
*str = str->substr(1);\
c = str->front();\
}\
} break;

            switch(c) {
                L2C1(':', ':');
                L2C1('!', '=');
                L2C1('%', '=');
                L2C1('^', '=');
                L2C2('<', '<', '=');
                L2C2('>', '>', '=');
                L2C2('=', '=', '>');
                L2C2('+', '+', '=');
                L2C2('&', '&', '=');
                L2C2('|', '|', '=');
                L2C2('*', '=', '/');
                L2C3('/', '/', '=', '*');
                L2C3('-', '-', '=', '>');
                default:
                    break;
            }
            val+=c;
            *str = str->substr(1);
        }
    }
    return val;
}

void Parser::parse(const char* fileDir) {
    unit = ifstream(fileDir);

    if (unit.is_open()) {
        string line;
        bool isComment = false;
        while (getline(unit, line)) {
            while(!line.empty()) {
                string token = nextToken(&line);
                if(token == "//") break;
                if(token == "/*") isComment = true;
                if(!isComment) {
                    cout << token << endl;
                }
                if(token == "*/") isComment = false;
            }
        }
        unit.close();
    } else {
        cout << "Unable to retrieve the file." << endl;
    }
}