#pragma once
#include <vector>
#include <string>
#include <locke/Util.h>

namespace locke {
    struct Token {
        string_t content;
        string_t type;

        Token();
    };
    struct TokenizerOptions {
        bool rememberComments = false;

        TokenizerOptions();
    };

    struct TokenizerError {
        size_t line, col;
        string_t error;

        TokenizerError(size_t line, size_t col, string_t error);
    };


    struct TokenizerState {
        TokenizerOptions* opts;
        std::vector<Token*> previousTokens;
        std::vector<TokenizerError> errors;
        Token* current;

        // the current character
        size_t index = 0;
        size_t length = 0;
        // metadata like line and column
        // will be used for error messages
        size_t line = 0;
        size_t col = 0;

        TokenizerState(TokenizerOptions* opts);

        // create errors, debugging
        void error(string_t message);

        // pushing tokens
        // these all do the same thing:
        // push the current token into the previousTokens vector and create a new token
        void pushToken();
        void pushToken(string_t type);
        void pushToken(string_t type, string_t content);

        // token manipulation
        void append(LOCKE_CHAR_T c);
        size_t contentLength();

        bool isLast() const;
        bool isUnknown();
    };

    struct TokenizerResult {
        std::vector<Token> tokens;
        std::vector<TokenizerError> errors;
    };

    /**
     * Tokenize a string.
     * @param content The string to tokenize.
     * @return A vector of tokens.
     */
    TokenizerResult tokenize(const string_t& content, TokenizerOptions options = TokenizerOptions());
    /**
     * Separates
     * @param source
     * @return
     */
    std::vector<std::string> separate(const string_t& source);
}