#include <iostream>
#include <string>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence (end with ';'): ";
    getline(std::cin, sentence, ';');

    cout << "You entered: " << sentence << endl;
    return 0;
}