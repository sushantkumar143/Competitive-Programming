#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string remix;
    cin >> remix;

    vector<string> words;
    string temp;

    for (int i = 0; i < remix.size(); ) {
        if (i + 2 < remix.size() && remix.substr(i, 3) == "WUB") {
            if (!temp.empty()) {
                words.push_back(temp);
                temp.clear();
            }
            i += 3;
        } else {
            temp += remix[i];
            i++;
        }
    }

    if (!temp.empty()) {
        words.push_back(temp);
    }

    for (int i = 0; i < words.size(); i++) {
        if (i > 0) cout << " ";
        cout << words[i];
    }

    return 0;
}
