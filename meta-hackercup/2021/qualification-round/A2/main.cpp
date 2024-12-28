#include <bits/stdc++.h>
using namespace std;

const int N = 26, INF = 0x3f3f3f3f;
int n, k, dist[N][N];
string s;

void solve() {
    cin >> s >> k, n = s.size();

    memset(dist, 0x3f, sizeof(dist));
    while (k--) {
        string q;
        cin >> q;
        dist[q[0] - 'A'][q[1] - 'A'] = 1;
    }

    for (int i = 0; i < N; ++i)
        dist[i][i] = 0;
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = INT_MAX;
    for (int targ = 0; targ < N; ++targ) {
        int here = 0;
        bool f = 1;
        for (int i = 0; i < n; ++i) {
            int ind = s[i] - 'A';
            f &= (dist[ind][targ] != INF);
            here += dist[ind][targ];
        }

        if (f)
            ans = min(ans, here);
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

