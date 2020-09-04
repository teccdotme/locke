#pragma once
#include <cstdint>
#include <string>
#include <utility>
#include <temila/Definitions.h>
#include <temila/regex.h>

using namespace std;

namespace locke::lexing {
    struct TokenMatch {
        uint64_t begin;
        uint64_t end;
    };

    class TokenType {
    protected:
        regex expr;
        vector<string> str;

        bool useRegex = false;
    public:
        TokenType(const string& expr) {
            this->expr = regex(expr);
            this->useRegex = true;
        }
        TokenType(vector<string> str) {
            this->str = std::move(str);
        }

        bool Matches(const string& s);
        TokenMatch* GetOccurrences(const string& s);
    };

    TokenType UNKNOWN(u8"u^");

    TokenType NULL_LITERAL = TokenType(u8"");
    TokenType STRING_LITERAL = TokenType(u8"");

    struct Token {
        TokenType type;
        string source;
        uint64_t num{};

        Token(const string& source, uint64_t num) : Token(NULL_LITERAL, source, num) {}

        Token(TokenType type, const std::string& source, uint64_t num) : type(type), source(source), num(num) {}
    };
}