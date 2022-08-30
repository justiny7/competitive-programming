#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 69;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<pair<ll, ll>>> w(N);
    for (int i = 0; i < n; ++i) {
        int hh, ww;
        cin >> hh >> ww;

        w[hh].push_back({ww, ww * hh});
    }

    for (int i = 0; i < N; ++i) {
        sort(w[i].begin(), w[i].end());
        for (int j = 1; j < w[i].size(); ++j)
            w[i][j].second += w[i][j - 1].second;
    }

    while (q--) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;

        ll res = 0;
        for (int i = hs + 1; i < hb; ++i) {
            auto ub = lower_bound(w[i].begin(), w[i].end(), pair<ll, ll>{wb, 0});
            auto lb = upper_bound(w[i].begin(), w[i].end(), pair<ll, ll>{ws, LLONG_MAX});

            if (ub != w[i].begin() && lb != w[i].end()) {
                --ub;
                res += ub->second - (lb == w[i].begin() ? 0 : prev(lb)->second);
            }
        }

        cout << res << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

