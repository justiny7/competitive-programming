#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=70;
ll num[mxN];

void solve() {
    ll k, n=0; cin >> k;
    if (k&1)
        return void(cout << "-1\n");
    for (ll p=2; p<=1e18; p*=2, ++n)
        num[n]=p-2;
    vector<int> step;
    for (int i=n-1; i; --i)
        while (k>=num[i])
            step.push_back(i), k-=num[i];
    cout << accumulate(step.begin(), step.end(), 0) << '\n';
    for (int i:step) {
        cout << "1 ";
        for (int j=0; j<i-1; ++j)
            cout << "0 ";
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

