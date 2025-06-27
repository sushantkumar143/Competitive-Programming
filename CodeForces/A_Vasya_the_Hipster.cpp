#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin  >> a >> b;

    int ans1 = min(a,b);
    int ans2 = 0;
    if(a<b){
        a -= b;
        ans2 = a/2;
    }
    else{
        b-=a;
        ans2 = b/2;
    }
    if(ans2<0) ans2 *= -1;
    cout << ans1 << " " << ans2;
}