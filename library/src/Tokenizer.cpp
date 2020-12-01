#include <locke/Tokenizer.h>
#include <locke/TokenTypes.h>
#include <locke/internal/TokenizationUtils.h>

#include <utility>

using namespace locke;

TokenizerState::TokenizerState(TokenizerOptions* opts) {
    this->opts = opts;
    this->previousTokens = std::vector<Token*>();
    this->errors = std::vector<TokenizerError>();
    current = new Token();
}

void TokenizerState::error(string_t message) {
    errors.emplace_back(line, col, std::move(message));
}
void TokenizerState::pushToken() {
    if (current->type == TYPE_UNKNOWN && current->content.empty())
        return;
    previousTokens.push_back(current);
    current = new Token();
}
void TokenizerState::pushToken(string_t type) {
    pushToken();
    current->type = type;
}
void TokenizerState::pushToken(string_t type, string_t content) {
    pushToken(type);
    current->content = content;
}
void TokenizerState::append(LOCKE_CHAR_T c) {
    current->content += c;
}
size_t TokenizerState::contentLength() {
    return current->content.length();
}

bool TokenizerState::isLast() const {
    return index == length - 1;
}

bool TokenizerState::isUnknown() {
    return current->type == TYPE_UNKNOWN;
}

// actual tokenizer

void interpret(LOCKE_CHAR_T character, TokenizerState& state) {
    // check if the current read token is a string
    if (state.current->type == TYPE_STRING) {
        // check if previous character is escape character
        size_t charIndex = state.contentLength() - 1;
        if (state.current->content[charIndex] == '\\') {
            switch (character) {
                case '\\':
                case '"':
                    state.current->content[charIndex] = character;
                    break;
                default:
                    state.error("Invalid escape character");
            }
            goto stringLastChecks;
        }
        // check if current char is double quote
        if (character == '"') {
            state.pushToken();
            return;
        } else // otherwise just append the character
        {
            state.append(character);
        }
        stringLastChecks:
        if (state.isLast()) {
            state.error("String not closed.");
        }


        // return because we're done with appending/ending the string
        return;
    }

    // check if inside character
    if (state.current->type == TYPE_CHAR) {
        size_t length = state.contentLength();
        if (state.current->content == "\\") {
            // escaped character, append
            state.append(character);
        }
        // if end of character
        if (character == '\'') {
            // check if token is empty
            if (length < 1) {
                state.error("No character inside character token");
            }
            if (state.current->content[0] != '\\' && length > 1)
                state.error("Too long character");
            state.pushToken();
            return;
        }
        if (state.isLast())
            state.error("Character not closed.");
    }

    // check if character is a double quote or single quote
    if (character == '"' || character == '\'') {
        // create a new token & return because
        // next interpretation will take care of content
        // type will be char if character is single quote and string otherwise
        state.pushToken(character == '\'' ? TYPE_CHAR : TYPE_STRING);
        return;
    }
    if (character == ' ') {
        if (state.isUnknown()) {
            if (analyzeForKeywords(state.current->content)) {
                state.current->type = TYPE_KEYWORD;
                state.pushToken();
            }
        }
        return;
    }
    state.append(character);
}

TokenizerResult locke::tokenize(const string_t& content, TokenizerOptions opts) {
    // initialise state
    TokenizerState state{&opts};
    // get size of content
    // will be used a few times
    size_t csize = content.size();
    state.length = csize;
    state.line = 1;
    for (size_t i = 0; i < csize; i++) {
        auto c = content[i];
        state.index = i;
        if (c == '\n') {
            state.col = 0;
            state.line++;
        } else state.col++;
        interpret(c, state);
    }
    std::vector<Token> tokens;
    for (Token* token : state.previousTokens)
        tokens.push_back(*token);

    TokenizerResult res{};
    res.tokens = tokens;
    res.errors = state.errors;
    return res;
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

TokenizerError::TokenizerError(size_t line, size_t col, string_t error) {
    this->line = line;
    this->col = col;
    this->error = std::move(error);
}

Token::Token() {
    content = "";
    type = TYPE_UNKNOWN;
}
