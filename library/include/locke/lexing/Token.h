#pragma once
#include <cstdint>
#include <string>
#include <utility>
#include <locke/Definitions.h>
#include <locke/regex.h>
#include <locke/util.h>

using namespace std;

namespace locke::lexing {
    struct TokenMatch {
        uint64_t begin;
        uint64_t end;
    };

    class TokenType {
    protected:
        regex expr;

        bool useRegex = false;
    public:
        TokenType(const string& expr) {
            this->expr = regex(expr);
        }
        TokenType(vector<string> strs) {
            // init pattern
            string pattern = "(";
            // escape all strings
            for (auto str : strs) {
                string* nstr = (string*) malloc(str.length() * 2 * sizeof(uint8_t));
                for (char c : str) {
                    // append escaped character
                    nstr->append("\\" + c);
                }
                // append pattern
                pattern.append(nstr->c_str());
            }
            // set pattern to regex
            this->expr = regex(pattern);
        }

        bool Matches(const string& s);
        TokenMatch* GetOccurrences(const string& s);
    };

    TokenType UNKNOWN(u8"u^");

    TokenType STRING_LITERAL = TokenType(u8"");
    TokenType KEYWORD = TokenType(vector<string>{u8"function", u8"var"});
    TokenType NUMBER_LITERAL = TokenType(u8"\\d+(\\.\\d+(d|f|i|l)?)?");
    TokenType NULL_LITERAL = TokenType(u8"null");
    TokenType IDENTIFIER = TokenType(u8"");

    struct Token {
        TokenType type;
        string source;
        uint64_t num{};
        TokenMatch match;

        Token(const string& source, uint64_t num) : Token(NULL_LITERAL, source, num) {}

        Token(TokenType type, const std::string& source, uint64_t num) : type(type), source(source), num(num) {}
    };
}