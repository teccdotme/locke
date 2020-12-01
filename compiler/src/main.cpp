#include <iostream>
#include <fstream>
#include <string>
#include <locke/Tokenizer.h>

using namespace std;

int main(int argc, char** argv) {
    cout << "Locke compiler." << endl;
    cout << "This is a test build, and probably does not work." << endl;

    std::string test = R"(function testFunction() {} 't' 't*' '' '\'' "\\"" "testString")";
    locke::TokenizerResult res = locke::tokenize(test);
    if (!res.tokens.empty()) {
        cout << "Tokens from test:" << endl;
        for (const locke::Token& token : res.tokens) {
            cout << token.type << ": " << token.content << endl;
        }
    } else cout << "No tokens were found." << endl;

    if (!res.errors.empty()) {
        cout << "Errors from test:" << endl;
        for (const locke::TokenizerError& error : res.errors) {
            cout << "  Line " << error.line << ", column " << error.col << ": " << error.error << std::endl;
        }
    } else cout << "No errors were found.";
}