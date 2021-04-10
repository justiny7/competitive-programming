#include <bits/stdc++.h>
using namespace std;

const int N = 51, M = 101;
int n, b[N][2];
string s[N];
bool done[N];

void solve() {
    cin >> n;
    string e[2], ret;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        b[i][0] = n;
        b[i][1] = -1;
    }
    for (int t = 0; t < 2; ++t) {
        memset(done, 0, sizeof(done));
        for (int i = 0; i < M; ++i) {
            char here = '~';
            for (int j = 0; j < n; ++j) {
                if (!done[j] && (i >= s[j].size() || s[j][i] == '*')) {
                    done[j] = 1;
                    b[j][t] = i;
                }
                if (done[j])
                    continue;
                if (here == '~')
                    here = s[j][i];
                else if (s[j][i] != here) {
                    cout << "*\n";
                    return;
                }
            }
            if (here != '~')
                e[t] += here;
        }
        for (int i = 0; i < n; ++i)
            reverse(s[i].begin(), s[i].end());
    }
    for (int i = 0; i < n; ++i)
        for (int j = b[i][0] + 1; j < s[i].size() - 1 - b[i][1]; ++j)
            if (s[i][j] != '*')
                ret += s[i][j];
    reverse(e[1].begin(), e[1].end());
    ret = e[0] + ret + e[1];
    cout << ret << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}
