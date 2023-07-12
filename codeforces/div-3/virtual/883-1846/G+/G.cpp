#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int conv(string s) {
    int p = 1, res = 0;
    while (s.size()) {
        res += p * (s.back() - '0');
        p *= 2;
        s.pop_back();
    }
    return res;
}
void solve() {
    int n, m;
    string st;
    cin >> n >> m >> st;

    vector<int> d(m);
    vector<string> rem(m), add(m);
    for (int i = 0; i < m; ++i)
        cin >> d[i] >> rem[i] >> add[i];

    vector<int> res(1 << N, INT_MAX);
    res[conv(st)] = 0;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({0, st});
    while (pq.size()) {
        auto [c, cur] = pq.top();
        pq.pop();

        if (c != res[conv(cur)])
            continue;

        for (int i = 0; i < m; ++i) {
            string nxt = cur;
            for (int j = 0; j < n; ++j) {
                if (rem[i][j] == '1')
                    nxt[j] = '0';
                else if (add[i][j] == '1')
                    nxt[j] = '1';
            }

            if (res[conv(nxt)] > c + d[i]) {
                res[conv(nxt)] = c + d[i];
                pq.push({c + d[i], nxt});
            }
        }
    }

    if (res[0] != INT_MAX)
        cout << res[0] << '\n';
    else
        cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

