#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll f(int r, int c) {
    ll cur=0, ans=20151125;
    for (ll i=0; i<r+c-1; ++i)
        cur+=i+1;
    cur-=r-1;
    while (--cur)
        ans=(ans*252533)%33554393;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << f(2947, 3029) << '\n';
}

