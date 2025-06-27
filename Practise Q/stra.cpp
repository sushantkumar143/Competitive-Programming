#include<iostream>
using namespace std;

void print(int n){
    if(n == 0) return;
    cout << "*";
    print(n-1);
}

void fun(int n, int line){
    if(n==line) return;
    print(line);
    cout << "\n";
    fun(n, line-1);
}

int main(){
    int n;
    cin >> n;
    fun(n, n);
}