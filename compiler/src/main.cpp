#include <iostream>
#include <fstream>
#include <string>
#include <locke/Tokenizer.h>

using namespace std;

int main(int argc, char** argv) {
    cout << "Locke compiler." << endl;
    cout << "This is a test build, and probably does not work." << endl;

    if (argc != 2) {
        cout << "This command requires a file." << endl;
        return -1;
    }

    std::string content;
    std::ifstream file(argv[1]);
    while (file.is_open() && file.) {
        file >> content;
    }
}