#include <locke/lexing/Token.h>
#include <algorithm>

using namespace std;

namespace locke::lexing {
    bool TokenType::Matches(const string &s) {
        if (this->useRegex) {
            return regex_match((const regex*) &expr).setSubject(rstring(s)).match() != 0;
        } else {
            auto endi = end(this->str);
            auto match = find(begin(this->str), endi, s);

            return match != endi;
        }
    }

    TokenMatch* TokenType::GetOccurrences(const string &s) {
        // set up regex match object
        regex_match rm((const regex*) &expr);
        rm.setFindAll(true).setSubject(rstring(s));
        jp::VecNum matches;
        rm.setNumberedSubstringVector(&matches);
        // find all matches
        size_t count = rm.match();
        vector<TokenMatch> tokenMatches;
        for (size_t i = 0; i < count; ++i) {
            // gets current match
            // [0] is the full match, anything above it is capture groups
            auto match = matches[i][0];
            TokenMatch tokenMatch{};
            // add data to tokenMatch
            tokenMatch.begin = s.find(match);
            tokenMatch.end = tokenMatch.begin + match.length();
            // insert it into tokenMatches
            tokenMatches[tokenMatches.size()] = tokenMatch;
        }
        // convert into TokenMatch* as its the return type
        return tokenMatches.data();
    }

}