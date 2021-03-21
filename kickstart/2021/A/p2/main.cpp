#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 10;
int r, c, a[mxN][mxN], hor[mxN][mxN], ver[mxN][mxN];

void solve() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
            hor[i][j] = ver[i][j] = a[i][j];
            hor[i][j] += hor[i][j - 1];
        }
    }
    for (int i = 1; i <= c; ++i)
        for (int j = 1; j <= r; ++j)
            ver[j][i] += ver[j - 1][i];
    int ans = 0;
    for (int len = 2; len <= 500; ++len) {
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (i + len <= r + 1 && j + len * 2 <= c + 1) {
                    bool rt = ver[i + len - 1][j + len * 2 - 1] - ver[i - 1][j + len * 2 - 1] == len,
                         lf = ver[i + len - 1][j] - ver[i - 1][j] == len,
                         tp = hor[i][j + len * 2 - 1] - hor[i][j - 1] == len * 2,
                         bt = hor[i + len - 1][j + len * 2 - 1] - hor[i + len - 1][j - 1] == len * 2;
                    if (rt && tp)
                        ++ans;
                    if (rt && bt)
                        ++ans;
                    if (lf && tp)
                        ++ans;
                    if (lf && bt)
                        ++ans;
                }
                if (i + len * 2 <= r + 1 && j + len <= c + 1) {
                    bool rt = ver[i + len * 2 - 1][j + len - 1] - ver[i - 1][j + len - 1] == len * 2,
                         lf = ver[i + len * 2 - 1][j] - ver[i - 1][j] == len * 2,
                         tp = hor[i][j + len - 1] - hor[i][j - 1] == len,
                         bt = hor[i + len * 2 - 1][j + len - 1] - hor[i + len * 2 - 1][j - 1] == len;
                    if (rt && tp)
                        ++ans;
                    if (rt && bt)
                        ++ans;
                    if (lf && tp)
                        ++ans;
                    if (lf && bt)
                        ++ans;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}
