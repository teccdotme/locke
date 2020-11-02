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

std::vector<std::string> util::regexSplit(Regex expr, const std::string& source) {
    throw std::exception("regex split is not ready");
    // make sure the expression is valid
    if (!expr)
        throw std::exception("Invalid regular expression.");

    if (!expr.match(source))
        return singleton<std::string>(source);

    std::string target = copyString(source);

    // initialize match stuff
    jp::VecNas nas;
    Match match = expr.getMatchObject()
            .setSubject(source)
            .setModifier("g")
            .setNamedSubstringVector(&nas);
    size_t matches = match.match();
    // directly copied from jpcre2s page
    for (size_t i=0; i < nas.size(); ++i) {
        // i=0 is the first match found, i=1 is the second and so forth
        for (auto const& entry : nas[i]) {
            entry.second;
        }
    }
}
