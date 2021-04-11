#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69;
int n, a[N], inds[N], par[N], sz[N];
ll p, cnt;
bool vis[N];

int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int x, int y) {
    if ((x = find(x)) == (y = find(y)))
        return 0;
    if (sz[x] < sz[y])
        swap(x, y);
    par[y] = x, sz[x] += sz[y];
    --cnt;
    return 1;
}

void solve() {
    cin >> n >> p;
    cnt = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        inds[i] = i, vis[i] = 0;
        par[i] = i, sz[i] = 1;
    }
    sort(inds + 1, inds + n + 1, [&](int x, int y) {
        return a[x] < a[y];
    });
    ll ans = 0;
    for (int t = 1; t <= n; ++t) {
        int c = inds[t];
        //cout << t << " " << c << '\n';
        if (a[c] >= p)
            break;
        if (vis[c])
            continue;
        for (int i = c + 1; i <= n; ++i) {
            if (a[i] % a[c])
                break;
            if (merge(i, c)) {
                ans += a[c];
                vis[i] = 1;
            }
        }
        for (int i = c - 1; i; --i) {
            if (a[i] % a[c])
                break;
            if (merge(i, c)) {
                ans += a[c];
                vis[i] = 1;
            }
        }
        //cout << "now ans: " << ans << '\n';
    }
    ans += p * (cnt - 1);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
