#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 69;
int n, m, q;
int cnt[N];
char g[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> q;

    int tot = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j], tot += (g[i][j] == '*');

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cnt[i] += (g[j][i] == '*');

    while (q--) {
        int r, c;
        cin >> r >> c, --r, --c;

        if (g[r][c] == '*')
            --cnt[c], --tot, g[r][c] = '.';
        else
            ++cnt[c], ++tot, g[r][c] = '*';

        int cur = 0, col = 0, have = 0;
        while (cur + n <= tot) {
            cur += n;
            have += cnt[col++];
        }

        // cout << col << " " << cur << " " << have << '\n';

        for (int i = 0; cur + i < tot; ++i)
            have += (g[i][col] == '*');

        cout << tot - have << '\n';
    }
}

