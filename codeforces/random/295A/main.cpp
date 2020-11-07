#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+5;
int n, m, k;
ll a[mxN], o[mxN], p[mxN];
array<int, 3> op[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=m; ++i)
        cin >> op[i][0] >> op[i][1] >> op[i][2];
    while (k--) {
        int x, y;
        cin >> x >> y;
        ++o[x], --o[y+1];
    }
    for (int i=1; i<=m; ++i) {
        o[i]+=o[i-1];
        ll v=o[i]*op[i][2];
        p[op[i][0]]+=v, p[op[i][1]+1]-=v;
    }
    for (int i=1; i<=n; ++i)
        cout << a[i]+(p[i]+=p[i-1]) << (i^n?" ":"\n");
}

