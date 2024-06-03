#include <iostream>
#include <string>

using namespace std;

class SentenceProcessor {
public:
    void getInput() {
        cout << "Enter a sentence (end with ';'): ";
        getline(cin, sentence, ';');
    }

    void displaySentence() {
        cout << "You entered: " << sentence << std::endl;
    }

private:
    string sentence;
};

int main() {
    SentenceProcessor processor;
    processor.getInput();
    processor.displaySentence();
    return 0;
}