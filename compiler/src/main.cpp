#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    cout << "Locke compiler." << endl;
    cout << "This is a test build." << endl;

    if (argc != 2) {
        cout << "This command requires a file." << endl;
        return -1;
    }
}