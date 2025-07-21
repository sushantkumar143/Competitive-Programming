#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n >= 0) {
        cout << n << endl;
    } else {
        int option1 = n / 10; 
        int lastDigit = n % 10;
        int secondLastRemoved = (n / 100) * 10 + lastDigit; 
        cout << max(option1, secondLastRemoved) << endl;
    }
}
