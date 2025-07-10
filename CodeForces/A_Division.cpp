#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        if(n >= 1900) cout << "Division 1" << '\n';
        else if(n >= 1600 && n <= 1899) cout << "Division 2" << '\n';
        else if(n >= 1400 && n <= 1599) cout << "Division 3" << '\n';
        else if(n <= 1399) cout << "Division 4" << '\n';
    }
}
