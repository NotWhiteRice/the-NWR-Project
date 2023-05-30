#pragma once


#include <fstream>
#include <string>

#include "token.hpp"

using std::ifstream;
using std::string;

/// @brief An object that tokenizes a given file
/// @note Supported languages: C++ and the programming language this project will run on.
class Lexer {
private:

    /// @brief True if the lexer is invalid, either by reaching the end of the file or by being unable to retrieve it
    bool eof;
    
    /// @brief The current line fed into the lexer
    string line;

    /// @brief The file being operated on
    ifstream unit;

    /// @brief len: characters left in current line, size: the amount of characters in the file
    size_t len, size;

    /// @brief Moves the lexer forward by i characters
    /// @param i [in, const] The amount of characters the lexer will skip over
    /// @note Has bounds-checking
    void advance(const size_t i = 1);
public:
    Lexer(const char* dir);

    /// @brief Returns true if the lexer has reached the end of the file or is invalid
    bool operator!() const;

    /// @brief Returns whether or not the lexer is still valid
    operator bool() const;

    /// @brief Returns the next token from the file.
    /// @note Returns an EOF token if it be the end of the file
    Token nextToken();
    /// @brief Moves the lexer to the next line in the file
    /// @note Does nothing if the lexer is at the end of the file
    void nextLine();
};
