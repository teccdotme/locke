#pragma once

#include <string>
#include <vector>
#include <locke/lexing/Token.h>

using namespace std;
using namespace locke::lexing;

namespace locke::parsing {
    class Node {
        vector<Token> content;
        vector<Node> children;

        public: 
        Node(vector<Token> tokens) : Node(tokens, vector<Node>{}) {}
        Node(vector<Token> tokens, vector<Node> children) : content(tokens), children(children) {};

        vector<Token> GetTokens() { return content; };
    };

    template<typename numType>
    class NumberNode : public Node {
    public:
        NumberNode(vector<Token> tokens, numType value) : Node(tokens) {};

        numType Value();
    };
    
}