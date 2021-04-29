#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int V = 3e6 + 69;
int m; ll n, cnt[V], ret[V];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }
    for (int i = 1; i < V; ++i) {
        if (!cnt[i])
            continue;
        for (int j = i; j < V; j += i) {
            if (j / i == i)
                ret[j] += cnt[i] * (cnt[i] - 1);
            else
                ret[j] += cnt[i] * cnt[j / i];
        }
    }
    for (int i = 1; i < V; ++i)
        ret[i] += ret[i - 1];
    cin >> m;
    while (m--) {
        int q; cin >> q;
        cout << n * (n - 1) - ret[q - 1] << '\n';
    }
}
