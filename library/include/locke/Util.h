#pragma once

#include <string>
#include <vector>
#include <jpcre2.hpp>

#ifndef LOCKE_CHAR_T
#define LOCKE_CHAR_T char
#endif

typedef jpcre2::select<LOCKE_CHAR_T> jp;
typedef jp::Regex Regex;
typedef jp::RegexMatch Match;
typedef std::basic_string<LOCKE_CHAR_T> string_t;

namespace locke::util {
    template<typename vec_t>
    std::vector<vec_t> singleton(vec_t value);

    string_t copyString(const string_t& source);

    std::vector<string_t> regexSplit(Regex expr, const string_t& source);
    std::vector<string_t> split(string_t delim, const string_t& source);
    std::vector<string_t> split(size_t position, const string_t& source);
}