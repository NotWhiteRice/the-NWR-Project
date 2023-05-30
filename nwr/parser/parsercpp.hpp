#pragma once


/// @brief Parses C++ files [Currently the default language for the NWR Project]
class ParserCPP {
public:
    /// @brief Parses a C++ file
    /// @param dir [in, const] The directory of the C++ file being parsed
    void parse(const char* dir);
} typedef Parser;