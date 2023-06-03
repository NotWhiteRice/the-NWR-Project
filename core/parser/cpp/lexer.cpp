#include "lexer.hpp"

namespace nwr {
    LexerCPP::LexerCPP(const char *file) : UniversalLexer(file) {}

    Token LexerCPP::nextToken() {
        skipWhitespace(true);
        Token token = validateLexer();
        if(token.getType() == UniversalLexer::t_EOF) return token;

        addToken("\%:%:", 2, t_DHASH);
        addToken("//", 2, t_DFSLASH);
        addToken("/*", 2, t_COMMIN);
        addToken("*/", 2, t_COMMOUT);
        addToken("<:", 2, t_LBRACE);
        addToken("<%", 2, t_LCURLY);
        addToken(":>", 2, t_RBRACE);
        addToken("%>", 2, t_RCURLY);
        addToken("&=", 2, t_AMPEREQ);
        addToken("&&", 2, t_DAMPER);
        addToken("|=", 2, t_LINEEQ);
        addToken("||", 2, t_DLINE);
        //addToken("%:", 2, t_HASH);
        addToken("##", 2, t_DHASH);
        addToken("^=", 2, t_CARETEQ);
        addToken("!=", 2, t_EXCEQ);
        addToken("::", 2, t_SCOPERES);
        addToken("(", 1, t_LPAREN);
        addToken("[", 1, t_LBRACE);
        addToken("{", 1, t_LCURLY);
        addToken(")", 1, t_RPAREN);
        addToken("]", 1, t_RBRACE);
        addToken("}", 1, t_RCURLY);
        addToken("&", 1, t_AMPER);
        addToken("~", 1, t_TILDE);
        addToken("|", 1, t_LINE);
        addToken("#", 1, t_HASH);
        addToken("^", 1, t_CARET);
        addToken(",", 1, t_COMMA);
        addToken("?", 1, t_QMARK);
        addToken("!", 1, t_EXCLAM);
        addToken(":", 1, t_COLON);
        addToken(";", 1, t_SEMICOLON);

        if(len >= 1) if(line.front() == '.' && !isdigit(line.at(1))) {
            advance();
            return Token(".", t_PERIOD);
        }
        token = UniversalLexer::nextToken();
        if(token.getType() == t_ID) {
            string val = token.getValue();
            if(val == "bool") token.type = t_TYPE;
            if(val == "char") token.type = t_TYPE;
            if(val == "char8_t") token.type = t_TYPE;
            if(val == "char16_t") token.type = t_TYPE;
            if(val == "char32_t") token.type = t_TYPE;
            if(val == "class") token.type = t_CLASS;
            if(val == "const") token.type = t_ATTR;
            if(val == "constexpr") token.type = t_ATTR;
            if(val == "constinit") token.type = t_ATTR;
            if(val == "default") token.type = t_ATTR;
            if(val == "double") token.type = t_TYPE;
            if(val == "enum") token.type = t_CLASS;
            if(val == "explicit") token.type = t_ATTR;
            if(val == "extern") token.type = t_ATTR;
            if(val == "false") token.type = t_TRUTH;
            if(val == "float") token.type = t_TYPE;
            if(val == "friend") token.type = t_ATTR;
            if(val == "inline") token.type = t_ATTR;
            if(val == "int") token.type = t_TYPE;
            if(val == "long") token.type = t_TYPE;
            if(val == "mutable") token.type = t_ATTR;
            if(val == "namespace") token.type = t_CLASS;
            if(val == "new") token.type = t_NEW;
            if(val == "noexcept") token.type = t_ATTR;
            if(val == "operator") token.type = t_OPER;
            if(val == "private") token.type = t_ATTR;
            if(val == "protected") token.type = t_ATTR;
            if(val == "public") token.type = t_ATTR;
            if(val == "return") token.type = t_RETURN;
            if(val == "short") token.type = t_TYPE;
            if(val == "signed") token.type = t_ATTR;
            if(val == "static") token.type = t_ATTR;
            if(val == "struct") token.type = t_CLASS;
            if(val == "template") token.type = t_ATTR;
            if(val == "thread_local") token.type = t_ATTR;
            if(val == "true") token.type = t_TRUTH;
            if(val == "union") token.type = t_CLASS;
            if(val == "unsigned") token.type = t_ATTR;
            if(val == "virtual") token.type = t_ATTR;
            if(val == "void") token.type = t_ATTR;
            if(val == "volatile") token.type = t_ATTR;
            if(val == "wchar_t") token.type = t_TYPE;
        }
        return token;
    }
}