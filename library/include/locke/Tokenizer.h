#pragma once
#include <vector>
#include <string>

namespace locke {
    struct Token {
        std::string content;
        std::string type;
    };

    std::vector<Token> tokenize(std::string file);
}