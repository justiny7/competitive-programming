#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j)
            cout << (j?" ":"") << ((i&1)?(1LL<<(i+j)):0);
        cout << endl;
    }
    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        int i=0, j=0;
        while (i<n-1 || j<n-1) {
            cout << i+1 << " " << j+1 << endl;
            if (bool(i&1)^bool(k&(1LL<<(i+j+1))))
                ++i;
            else
                ++j;
        }
        cout << n << " " << n << endl;
    }
}

