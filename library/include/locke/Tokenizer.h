#pragma once
#include <vector>
#include <string>
#include <locke/Util.h>

// using verbose strings because it makes debugging messages way clearer
// granted, not implemented yet
#define LOCKE_UNKNOWN_TYPE "unknown"
#define LOCKE_STRING_TYPE  "string"
#define LOCKE_COMMENT_TYPE "comment"
#define LOCKE_CHAR_TYPE    "character"
#define LOCKE_NUMBER_TYPE  "number"
#define LOCKE_ID_TYPE      "identifier"

namespace locke {
    struct Token {
        string_t content;
        string_t type;

        Token() {
            content = "";
            type = LOCKE_UNKNOWN_TYPE;
        }
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