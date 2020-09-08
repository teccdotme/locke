#include <locke/lexing/Tokenizer.h>
#include <utility>
#include <locke/lexing/Token.h>
#include <locke/Definitions.h>

using namespace std;

namespace locke::lexing {
    TokenList Tokenizer::Lex(TokenList list, const string& s) {
        // lexes all occurrences of all tokens in order
        // a bit repetitive, but hey at least i can avoid array hell
        if (STRING_LITERAL.Matches(s))
            list = DoOps(list, s, STRING_LITERAL);
        if (KEYWORD.Matches(s))
            list = DoOps(list, s, KEYWORD);
        if (NUMBER_LITERAL.Matches(s))
            list = DoOps(list, s, NUMBER_LITERAL);

        return list;
    }

    TokenList Tokenizer::Tokenize() {
        cout << "Starting tokenization process for file " << file << "..." << endl;
        cout << "Reading file..." << endl;
        auto list = TokenList(file);

        string content;
        ifstream stream(file);
        while (stream.is_open())
            stream >> content;

        cout << "File read successfully." << endl;

        cout << "Lexing tokens.." << endl;
        list = Lex(list, content);
        list = OrderList(list, content);


        return list;
    }

    TokenList Tokenizer::OrderList(TokenList original, string content) {
        original.First()
    }

    void TokenList::operator+=(Token t) {
        tokens[index] = std::move(t);
        index++;
    }

    TokenList DoOps(TokenList list, string s, TokenType type) {
        TokenMatch* occurrences = type.GetOccurrences(s);
        size_t length = arraySize(occurrences);

        // loops through each match
        for (size_t i = 0; i < length; ++i) {
            TokenMatch occurrence = occurrences[i];
            size_t length = occurrence.end - occurrence.begin;
            string* source = (string*) malloc(length * sizeof(jp::Char));
            s.copy((char*) source->c_str(), length, occurrence.begin);
            list += Token{type, (const string&) source, i};   
        }
        return list;
    }

}