#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, fact[21];

int main() {
    fact[1]=1;
    for (int i=2; i<=20; ++i)
        fact[i]=fact[i-1]*i;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (n==2)
        return cout << "1\n", 0;
    cout << (fact[n]/fact[n/2]/fact[n/2]/2)*fact[n/2-1]*fact[n/2-1] << '\n';
}

