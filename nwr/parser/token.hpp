#pragma once

#include <string>

using std::string;

/// @brief the NWR Project
namespace nwr {
    /// @brief Individual 'words' that the parser can use to parse a language.
    /// @note Supported languages: C++ and the programming language this project will run on.
    class Token {
    private:
        /// @brief The value of the current token
        string value;
        /// @brief The type of the current token
    int type;

    public:
    /// @brief The recognized types of tokens
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

    /// @brief Returns true if the token is of the given type
    /// @param type [in, const] The type being checked
    bool operator()(const Token::types type) const;

    /// @brief Returns the value of the token (e.g. "return", 1234, [, etc.)
    string is() const;

    } typedef Token;
}