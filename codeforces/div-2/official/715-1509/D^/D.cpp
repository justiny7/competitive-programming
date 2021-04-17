#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, c[3][2];
string s[3];

void solve() {
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
        c[i][0] = count(s[i].begin(), s[i].end(), '0');
        c[i][1] = count(s[i].begin(), s[i].end(), '1');
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (c[i][0] >= n && c[j][0] >= n) {
                int k = 0, l = 0;
                string ans;
                while (k < n * 2 || l < n * 2) {
                    if (k == n * 2)
                        ans += s[j][l++];
                    else if (l == n * 2)
                        ans += s[i][k++];
                    else {
                        if (s[i][k] == s[j][l])
                            ans += s[i][k], ++k, ++l;
                        else if (s[i][k] == '1')
                            ans += s[i][k++];
                        else
                            ans += s[j][l++];
                    }
                }
                cout << ans << '\n';
                return;
            }
            else if (c[i][1] >= n && c[j][1] >= n) {
                int k = 0, l = 0;
                string ans;
                while (k < n * 2 || l < n * 2) {
                    if (k == n * 2)
                        ans += s[j][l++];
                    else if (l == n * 2)
                        ans += s[i][k++];
                    else {
                        if (s[i][k] == s[j][l])
                            ans += s[i][k], ++k, ++l;
                        else if (s[i][k] == '0')
                            ans += s[i][k++];
                        else
                            ans += s[j][l++];
                    }
                }
                cout << ans << '\n';
                return;
            }
        }
    }
    assert(false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
