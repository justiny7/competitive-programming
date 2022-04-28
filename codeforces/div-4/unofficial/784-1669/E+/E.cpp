#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> cnt(26, vector<int>(26));
    while (n--) {
        string s;
        cin >> s;
        ++cnt[s[0] - 'a'][s[1] - 'a'];
    }

    long long res = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = j + 1; k < 26; ++k) {
                res += 1LL * cnt[i][j] * cnt[i][k];
                res += 1LL * cnt[j][i] * cnt[k][i];
            } 
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

