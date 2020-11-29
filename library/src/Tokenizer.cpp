#include <locke/Tokenizer.h>

using namespace locke;

// stores the state of the tokenizer
struct TokenizerState {
    TokenizerOptions* opts;
    std::vector<Token*> previousTokens;
    Token* current;

    // the current character
    size_t index = 0;
    // metadata like line and column
    // will be used for error messages
    size_t line = 0;
    size_t col = 0;

    TokenizerState(TokenizerOptions* opts) {
        this->opts = opts;
        this->previousTokens = std::vector<Token*>();
        current = new Token();
    }
    // deconstructor because memory
    ~TokenizerState() {
        previousTokens.clear();
        free(&previousTokens);
        free(current);
    }

    // pushing tokens
    // these all do the same thing
    void pushToken() {
        previousTokens.push_back(current);
        current = new Token();
    }
    void pushToken(string_t type) {
        pushToken();
        current->type = type;
    }
    void pushToken(string_t type, string_t content) {
        pushToken(type);
        current->content = content;
    }
};

void interpret(LOCKE_CHAR_T character, TokenizerState& state) {
    // check if the current read token is a string
    if (state.current->type == LOCKE_STRING_TYPE) {
        // check if end of string
        if (character == '"') {
            // if end of string, push token
            state.pushToken();
        } else // otherwise just append the character
            state.current->content.append(&character);
        // return because we're done with appending/ending the string
        return;
    }
    // check if character is a double quote
    if (character == '"') {
        // create a new string & return because
        // next interpretation will take care of string
        state.pushToken(LOCKE_STRING_TYPE);
        return;
    }
    state.current->content.append(&character);
    if (state.current->content == "//")
        state.current->type = LOCKE_COMMENT_TYPE;
}

std::vector<Token> locke::tokenize(const string_t& content, TokenizerOptions opts = TokenizerOptions()) {
    // initialise state
    TokenizerState state{&opts};
    // get size of content
    // will be used a few times
    int csize = content.size();
    state.line = 1;
    for (int i = 0; i < csize; i++) {
        auto c = content[i];
        if (c == '\n') {
            state.col = 0;
            state.line++;
        } else state.col++;
        interpret(c, state);
    }
    state.pushToken();
    std::vector<Token> tokens;
    for (Token* token : state.previousTokens)
        tokens.push_back(*token);

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
