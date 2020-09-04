#include <locke/lexing/Tokenizer.h>
#include <utility>
#include <locke/lexing/Token.h>
#include <locke/Definitions.h>

using namespace std;

namespace locke::lexing {
    Token Tokenizer::Lex(const TokenList& list, const string& s, size_t index) {
        Token token{s, index};

        if (STRING_LITERAL.Matches(s)) {
            TokenMatch* occurrences = STRING_LITERAL.GetOccurrences(s);
            size_t length = arraySize(occurrences);
            for (size_t i = 0; i < length; ++i) {
                TokenMatch m = occurrences[i];

            }
        }

        return token;
    }

    TokenList Tokenizer::Tokenize() {
        cout << "Tokenizing file " << file << "... " << endl;
        cout << "Reading file..." << endl;
        auto list = TokenList(file);

        string content;
        ifstream stream(file);
        while (stream.is_open())
            stream >> content;

        cout << "File read successfully." << endl;

        return list;
    }

    void TokenList::operator+=(Token t) {
        tokens[index] = std::move(t);
        index++;
    }

}