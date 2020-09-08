#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <locke/lexing/Token.h>

using namespace std;

namespace locke::lexing {
    class TokenList {
        string file;
        size_t index = 0;
        vector<Token> tokens;
    public:
        explicit TokenList(string file) {
            this->file = std::move(file);
            this->tokens = vector<Token>();
        }

        Token First();
        Token Previous();
        Token Current();
        Token Next();
        Token Last();

        void operator +=(Token t);

        size_t Available() {
            return Size() - Index();
        }
        [[nodiscard]] size_t Index() const {
            return index;
        }
        size_t Size() {
            return tokens.size();
        }
    };

    class Tokenizer {
    private:
        string file;
    public:
        explicit Tokenizer(string file) {
            this->file = std::move(file);
        }

        TokenList Tokenize();
    protected:

        TokenList Lex(TokenList, const string&);
        TokenList OrderList(TokenList, string);
    };
}