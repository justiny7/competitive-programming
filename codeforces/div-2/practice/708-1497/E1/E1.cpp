#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e7+1;
int spf[mxN];

void sieve() {
    for (int i=1; i<mxN; ++i) {
        if (i&1)
            spf[i]=i;
        else
            spf[i]=2;
    }
    for (ll i=3; i*i<mxN; i+=2)
        if (spf[i]==i)
            for (ll j=i*i; j<mxN; j+=i)
                spf[j]=i;
}

void solve() {
    int n, k, ans=1;
    cin >> n >> k;
    set<int> seen;
    for (int i=0; i<n; ++i) {
        int x, here=1; cin >> x;
        while (x>1) {
            int c=0, d=spf[x];
            while (x%d==0) {
                ++c;
                x/=d;
            }
            if (c&1)
                here*=d;
        }
        if (seen.count(here)) {
            ++ans;
            seen.clear();
        }
        seen.insert(here);
    }
    cout << ans << '\n';
}

int main() {
    sieve();
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

