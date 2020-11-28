#pragma once
#include <vector>
#include <string>
#include <locke/Util.h>

#define LOCKE_STRING_TYPE "string"

namespace locke {
    struct Token {
        string_t content;
        string_t type;
    };
    struct TokenizerOptions {
        bool rememberComments = false;

        TokenizerOptions();
    };

    /**
     * Tokenize a string.
     * @param content The string to tokenize.
     * @return A vector of tokens.
     */
    std::vector<Token> tokenize(const string_t& content, TokenizerOptions options);
    /**
     * Separates
     * @param source
     * @return
     */
    std::vector<std::string> separate(const string_t& source);
}