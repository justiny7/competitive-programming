#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e3 + 1;
int n, m, a, b;
ll ans, g_, x, y, z, g[N][N], mn[N][N];

void ins(deque<pair<ll, ll>> &dq, pair<ll, ll> x) {
    while (dq.size() && dq.back().first >= x.first)
        dq.pop_back();
    dq.push_back(x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> a >> b >> g_ >> x >> y >> z;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i][j] = g_;
            g_ = (g_ * x + y) % z;
        }
    }
    for (int i = 0; i < n; ++i) {
        deque<pair<ll, ll>> cur;
        for (int j = 0; j < m; ++j) {
            ins(cur, {g[i][j], j});
            if (j >= b && cur.front().second <= j - b)
                cur.pop_front();
            if (j >= b - 1)
                mn[i][j - b + 1] = cur.front().first;
        }
    }
    for (int i = 0; i + b <= m; ++i) {
        deque<pair<ll, ll>> cur;
        for (int j = 0; j < n; ++j) {
            ins(cur, {mn[j][i], j});
            if (j >= a && cur.front().second <= j - a)
                cur.pop_front();
            if (j >= a - 1)
                ans += cur.front().first;
        }
    }
    cout << ans << '\n';
}
