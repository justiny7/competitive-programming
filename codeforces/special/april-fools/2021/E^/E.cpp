#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int n, m, ans;
string s[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    int r = 0, c = 0, nr = n - 1, nc = m - 1, dst = INT_MAX;
    ans = (s[0][0] == '*');
    while (1) {
        for (int i = r; i < n; ++i) {
            for (int j = c; j < m; ++j) {
                if (i == r && j == c || s[i][j] == '.')
                    continue;
                int d = i + j - r - c;
                if (d < dst) {
                    dst = d;
                    nr = i, nc = j;
                }
            }
        }
        if (dst == INT_MAX)
            break;
        r = nr, c = nc, dst = INT_MAX;
        ++ans;
    }
    cout << ans << '\n';
}
