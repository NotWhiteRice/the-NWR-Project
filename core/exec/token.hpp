#pragma once

#include <string>

using std::string;

namespace nwr {
    class Token {
    private:
        string value;
        int type;

    public:
        enum types {
            t_UNKNOWN,

            t_TYPE,
            t_ID,

            t_DFSLASH,
            t_COMMIN,
            t_COMMOUT,

            t_PERIOD,

            t_RETURN,
            t_FLOAT,
            t_INT,
            t_EOF,
        };

        Token();
        Token(string str, int type);

        bool operator()(const Token::types type) const;
        string is() const;
    } typedef Token;
}