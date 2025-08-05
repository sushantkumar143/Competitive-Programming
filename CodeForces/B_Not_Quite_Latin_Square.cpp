#include <iostream>
#include <set>
using namespace std;

char findMissingLetter(string row) {
    set<char> letters = {'A', 'B', 'C'};
    for (char ch : row) {
        if (ch != '?') {
            letters.erase(ch);
        }
    }
    // Only one letter will be left
    return *letters.begin();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string row1, row2, row3;
        cin >> row1 >> row2 >> row3;

        char missing;
        if (row1.find('?') != string::npos) {
            missing = findMissingLetter(row1);
        } 
        else if (row2.find('?') != string::npos) {
            missing = findMissingLetter(row2);
        } 
        else {
            missing = findMissingLetter(row3);
        }

        cout << missing << endl;
    }
}
