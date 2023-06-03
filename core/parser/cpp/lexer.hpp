#include "../../interpreter/UniversalLexer.hpp"

namespace nwr {
    class LexerCPP : public UniversalLexer {
    public:
        LexerCPP(const char *file);

        enum cpp_tokens {
            t_UNKNOWN,
            t_EOF,
            t_INT,
            t_FLOAT,
            t_ID,

            t_DFSLASH,
            t_COMMIN,
            t_COMMOUT,

            t_LPAREN,
            t_LBRACE,
            t_LCURLY,
            t_RPAREN,
            t_RBRACE,
            t_RCURLY,

            t_AMPER,
            t_AMPEREQ,
            t_DAMPER,
            t_TILDE,
            t_LINE,
            t_LINEEQ,
            t_DLINE,
            t_HASH,
            t_DHASH,
            t_CARET,
            t_CARETEQ,

            t_PERIOD,
            t_COMMA,
            t_QMARK,
            t_EXCLAM,
            t_EXCEQ,
            t_COLON,
            t_SCOPERES,
            t_SEMICOLON,

            t_RETURN,
            t_TYPE,
            t_ATTR,
            t_TRUTH,

            t_CLASS,
            t_NEW,
            t_OPER,
        };

        Token nextToken() override;
    };
}