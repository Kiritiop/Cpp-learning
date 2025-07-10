#include <iostream>
using namespace std;

int main() {
    string word;
    getline(cin, word);
    while (word != "quit!") {
        if (word.length() > 4 && word[word.length() -3] != 'a' && word[word.length() -3] != 'e' && word[word.length() -3] != 'i' && word[word.length() -3] != 'o' && word[word.length() -3] != 'u' && word[word.length() -3] != 'y') {
            if (word[word.length()-1] == 'r' && word[word.length()-2] == 'o') {
                word[word.length()-1] = 'u';
                word += 'r';
            }
        }
        cout << word << endl;
        getline(cin, word);
        
    }

    
}