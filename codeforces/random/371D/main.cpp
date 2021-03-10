#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+5;
int n, q, a[mxN], cap[mxN], nxt[mxN];

int upd(int i, int x) {
    if (i>n)
        return n+1;
    if (a[i]+x>cap[i]) {
        x-=cap[i]-a[i];
        a[i]=cap[i];
        return nxt[i]=upd(nxt[i], x);
    }
    else {
        a[i]+=x;
        return i;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> cap[i], nxt[i]=i+1;
    cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t&1) {
            int i, x;
            cin >> i >> x;
            upd(i, x);
        }
        else {
            int x; cin >> x;
            cout << a[x] << '\n';
        }
    }
}

