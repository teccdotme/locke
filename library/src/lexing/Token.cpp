#include <temila/lexing/Token.h>
#include <algorithm>

using namespace std;

namespace locke {

    bool TokenType::Matches(const string &s) {
        if (this->useRegex) {
            return regex_match(s, expr);
        } else {
            auto endi = end(this->str);
            auto match = find(begin(this->str), endi, s);

            return match != endi;
        }
    }

    TokenMatch *TokenType::GetOccurrences(const string &s) {
        if (this-useRegex) {

        }
    }

}