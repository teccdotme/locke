#include <locke/Util.h>
#include <exception>

using namespace locke;
using namespace locke::util;

template<typename vec_t>
std::vector<vec_t> util::singleton(vec_t value) {
    // initialize, push, return.
    // simple.
    std::vector<vec_t> vec;
    vec.push_back(value);
    return vec;
}

std::string util::copyString(const std::string &source) {
    std::string target;
    source.copy(target.data(), 0, source.length());
    return target;
}


std::vector<string_t> util::split(string_t delim, const string_t &source) {
    std::vector<string_t> parts;
    size_t pos = source.find(delim);
    if (pos != string_t::npos) {
        parts.push_back(source.substr(0, pos));
        // i love recursion its brilliant
        for (const auto& part : split(delim, source.substr(pos))) {
            parts.push_back(part);
        }
    } else return singleton(source);
    return parts;
}

std::vector<string_t> util::split(size_t position, const string_t &source) {
    std::vector<string_t> parts;
    parts.push_back(source.substr(0, position));
    parts.push_back(source.substr(position));

    return parts;
}
