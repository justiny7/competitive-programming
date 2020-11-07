#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int mxN=2e5+1;
int n, ans[mxN], t=1;
pair<int, int> p[mxN];
bool done[mxN];

bool has(int i, int x) {
    return (p[i].fi==x || p[i].se==x);
}

void go(int i) {
    if (done[i])
        return;
    ans[t++]=i, done[i]=1;
    if (has(p[i].fi, p[i].se))
        go(p[i].fi);
    else
        go(p[i].se);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> p[i].fi >> p[i].se;
    for (int i=1; i<=n; ++i)
        if (!done[i])
            go(i);
    for (int i=1; i<=n; ++i)
        cout << ans[i] << (i^n?" ":"\n");
}

