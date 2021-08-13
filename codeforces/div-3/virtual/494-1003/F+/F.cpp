#include <bits/stdc++.h>
using namespace std;

const int N = 369;
int n, sz, ans, pref[N], mx[N][N]; // mx[i][j] = max same sequence starting from i and j
bool same[N][N];
string s[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> s[i], s[i] += ' ';
        sz += s[i].size();
        pref[i] = sz;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            same[i][j] = same[j][i] = s[i] == s[j];

    for (int i = n; i; --i)
        for (int j = n; j; --j)
            if (same[i][j])
                mx[i][j] = mx[i + 1][j + 1] + 1;

    // for (int i = 1; i <= n; ++i)
        // for (int j = 1; j <= n; ++j)
            // cout << mx[i][j] << " \n"[j == n];

    ans = sz;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int cnt = 0, len = j - i + 1;
            for (int k = i; k + len - 1 <= n; ++k) {
                if (mx[i][k] >= len) {
                    ++cnt;
                    k += len - 1;
                }
            }

            // cout << i << " " << j << " " << cnt << '\n';
            // cout << len << " " << pref[j] - pref[i - 1] << '\n';

            if (cnt > 1)
                ans = min(ans, sz - cnt * (pref[j] - pref[i - 1] - (len + 1)));
        }
    }
    
    cout << ans - 1 << '\n';
}

