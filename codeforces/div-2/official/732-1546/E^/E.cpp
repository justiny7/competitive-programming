#include <bits/stdc++.h>
using namespace std;

const int N = 569, MD = 998244353;
int n, tot, a[N * 2][N], cnt[N][N], ans[N];
bool vis[N * 2];

void solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    tot = 1;

    cin >> n;

    for (int i = 0; i < n * 2; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j], ++cnt[a[i][j]][j];

    for (int i = 0; i < n; ++i) {
        int here = -1;

        // find a row with a sole element of its column
        for (int j = 0; j < n * 2; ++j) {
            if (vis[j])
                continue;

            for (int k = 0; k < n; ++k)
                if (cnt[a[j][k]][k] == 1)
                    here = j;
        }

        // if it doesn't exist, then each element appears in
        // exactly 2 rows, so arbitrarily choose any row
        if (here < 0) {
            (tot *= 2) %= MD;
            here = 0;
            while (vis[here])
                ++here;
        }

        // remove this row
        vis[here] = 1;
        ans[i] = here + 1;
        for (int j = 0; j < n; ++j)
            --cnt[a[here][j]][j];

        // remove all rows that share an element with this row
        for (int j = 0; j < n * 2; ++j) {
            if (vis[j])
                continue;

            for (int k = 0; k < n; ++k)
                if (a[here][k] == a[j][k])
                    vis[j] = 1;

            if (vis[j]) {
                for (int k = 0; k < n; ++k)
                    --cnt[a[j][k]][k];
            }
        }
    }

    cout << tot << '\n';
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}

