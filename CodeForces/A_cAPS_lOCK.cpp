#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string word;
    cin >> word;

    bool condition1 = true; 
    bool condition2 = true; 

    for (int i = 0; i < word.length(); i++) {
        if (!isupper(word[i])) condition1 = false;
    }

    for (int i = 1; i < word.length(); i++) {
        if (!isupper(word[i])) condition2 = false;
    }

    if (condition1 || condition2) {
        for (int i = 0; i < word.length(); i++) {
            if (isupper(word[i])) word[i] = tolower(word[i]);
            else word[i] = toupper(word[i]);
        }
    }

    cout << word << endl;
    return 0;
}
