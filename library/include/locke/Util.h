#pragma once

#include <string>
#include <vector>
#include <jpcre2.hpp>

typedef jpcre2::select<char> jp;
typedef jp::Regex Regex;
typedef jp::RegexMatch Match;

namespace locke::util {
    template<typename vec_t>
    std::vector<vec_t> singleton(vec_t value);

    std::string copyString(const std::string& source);

    std::vector<std::string> regexSplit(Regex expr, const std::string& source);
    std::vector<std::string> split(std::string delim, const std::string& source);
}