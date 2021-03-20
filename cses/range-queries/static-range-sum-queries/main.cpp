#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, q;
vector<ll> bit;

void ins(int x, int ind) {
    ++ind;
    while (ind<=n)
        bit[ind]+=x, ind+=(ind&(-ind));
}

ll sum(int x) {
    ll ans=0;
    while (x>0)
        ans+=bit[x], x-=(x&(-x));
    return ans;
}

ll range(int l, int r) {
    return sum(r)-sum(l-1);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    bit.resize(n);
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        ins(a, i);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << range(a, b) << '\n';
    }
}
