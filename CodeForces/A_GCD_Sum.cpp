#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(long long n){
    long long temp = n;
    long long sum = 0;
    while (temp != 0)
    {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;
    }
    return sum;
}

int main()
{
    int cnt;
    cin >> cnt;
    while(cnt--)
    {
        long long n;
        cin >> n;
        long long curr = n;

        long long ans = -1;
        while (true)
        {
            long long int sm = sumOfDigits(curr);
            if(__gcd(curr, sm) > 1){
                ans = curr;
                break;
            }
            curr++;
        }
        cout << ans << endl;
    }
}