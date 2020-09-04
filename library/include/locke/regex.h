#pragma once
#include <jpcre2.hpp>
#include <cstdint>

typedef jpcre2::select<char> jp;
typedef jp::Regex regex;
typedef jp::RegexMatch regex_match;
typedef jp::String rstring;
