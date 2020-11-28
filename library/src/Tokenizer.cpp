#include <locke/Tokenizer.h>

using namespace locke;

// stores the state of the tokenizer
struct TokenizerState {
    TokenizerOptions* opts;
    std::vector<Token*> previousTokens;
    Token* current;
};

void nextState(TokenizerState* state, int charOffset, string_t word) {
    size_t sPos;
    if ((sPos = word.find('"')) != string_t::npos) {
        if (state->current->type == LOCKE_STRING_TYPE) {
            word.substr(charOffset)
            state->current->content
        }
    }
}

std::vector<Token> locke::tokenize(const string_t& content, TokenizerOptions opts = TokenizerOptions()) {
    // clean and simple
    std::vector<string_t> words = separate(content);
    std::vector<Token> tokens;
    TokenizerState state = {};

    for (string_t word : words) {
        nextState(&state,)
    }

    return tokens;
}

std::vector<string_t> locke::separate(const string_t& source) {
    // create words variable
    // needs to be in the top-level function scope so that
    // we can return it once it's been initialized
    std::vector<string_t> words;
    std::vector<string_t> lines = util::split("\n", source);
    for (const auto& currentLine : lines) {
        std::vector<string_t> line = util::split(" ", currentLine);
        for (const auto& word : line) {
            words.push_back(word);
        }
    }

    return words;
}

locke::TokenizerOptions::TokenizerOptions() = default;
