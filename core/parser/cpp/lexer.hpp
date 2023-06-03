#include "../../interpreter/UniversalLexer.hpp"

namespace nwr {
    class LexerCPP : public UniversalLexer {
    public:
        LexerCPP(const char *file);

        enum cpp_tokens {
        // Universal tokens
            t_UNKNOWN,
            t_EOF,
            t_INT,
            t_FLOAT,
            t_ID,

        // Comments and uncategorized tokens
            t_DFSLASH,
            t_COMMIN,
            t_COMMOUT,
            t_HASH,
            t_DHASH,

        // Parenthesis
            t_LPAREN,
            t_LBRACE,
            t_LCURLY,
            t_RPAREN,
            t_RBRACE,
            t_RCURLY,

        // Assignemnt and arithmetic operators
            t_EQUALS,
            t_PLUS,
            t_INC,
            t_PLUSEQ,
            t_MINUS,
            t_DEC,
            t_MINEQ,
            t_ASTER,
            t_ASTEREQ,
            t_FSLASH,
            t_FSEQUALS,
            t_PERCENT,
            t_PERCEQ,
            t_TILDE,
            t_AMPER,
            t_AMPEREQ,
            t_LINE,
            t_LINEEQ,
            t_CARET,
            t_CARETEQ,
            t_LSHIFT,
            t_LSEQUALS,
            t_RSHIFT,
            t_RSEQUALS,

        // Punctuation
            t_PERIOD,
            t_COMMA,
            t_DOTS,
            t_QMARK,
            t_COLON,
            t_SCOPERES,
            t_SEMICOLON,

        // Comparison symbols
            t_DEQUALS,
            t_EXCLAM,
            t_EXCEQ,
            t_DAMPER,
            t_DLINE,
            t_LTHAN,
            t_LTHANEQ,
            t_MTHAN,
            t_MTHANEQ,
            t_RANGE,

        // Keywords
            t_ALIGNAS,
            t_ALIGNOF,
            t_ASM,
            t_ATTR,
            t_AUTO,
            t_BREAK,
            t_CASE,
            t_CATCH,
            t_CLASS,
            t_CONCEPT,
            t_CONSTCAST,
            t_CONT,
            t_COAWAIT,
            t_CORETURN,
            t_COYIELD,
            t_DECLTYPE,
            t_DEFAULT,
            t_DELETE,
            t_DO,
            t_DYNACAST,
            t_ELSE,
            t_ENUM,
            t_EXPORT,
            t_FOR,
            t_GOTO,
            t_IF,
            t_NAMESPACE,
            t_NEW,
            t_NULLPTR,
            t_OPER,
            t_REGI,
            t_RECAST,
            t_REQUIRES,
            t_RETURN,
            t_SIZEOF,
            t_SASS,
            t_SCAST,
            t_STRUCT,
            t_SWITCH,
            t_TEMPLATE,
            t_THIS,
            t_TLOCAL,
            t_THROW,
            t_TRUTH,
            t_TRY,
            t_TYPE,
            t_TYPEDEF,
            t_TYPEID,
            t_TYPENAME,
            t_UNION,
            t_USING,
            t_WHILE,

            t_SPEC,
            t_DIR,
            t_LPRAG,
        };

        Token nextToken() override;
    };
}