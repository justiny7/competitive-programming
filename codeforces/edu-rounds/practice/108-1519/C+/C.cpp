#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69;
int n, u[N]; ll tot[N];
vector<ll> v[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> u[i];
        tot[i] = 0;
        v[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        v[u[i]].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        sort(v[i].rbegin(), v[i].rend());
        int sz = v[i].size();
        for (int j = 1; j < sz; ++j)
            v[i][j] += v[i][j - 1];
        for (int k = 1; k <= sz; ++k)
            for (int j = 0; j + k <= sz; j += k)
                tot[k] += v[i][j + k - 1] - (j ? v[i][j - 1] : 0);
    }
    for (int i = 1; i <= n; ++i)
        cout << tot[i] << " \n"[i == n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
