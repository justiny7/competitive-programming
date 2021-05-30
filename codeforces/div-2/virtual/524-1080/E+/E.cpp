#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 269, C = 26, M = 1e9 + 9;
int n, m, cnt[N][C], g[N][N];
ll p[C];
bool ok[N];

void prep() {
    for (int i = 0; i < C; ++i) {
        ll x = uid(69420, 6969420);
        if (x % 2 == 0)
            ++x;
        p[i] = x;
    }
}

ll manacher(vector<ll> &s) {
    int sz = s.size();
    ll ret = 0;
    array<vector<int>, 2> p = {vector<int>(sz + 1), vector<int>(sz)};
    for (int z = 0; z < 2; ++z) {
        for (int i = 0, l = 0, r = 0; i < sz; ++i) {
            int t = r - i + !z;
            if (i < r)
                p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < sz && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r)
                l = L, r = R;
        }
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < sz; ++j)
            ret += p[i][j] + i;
    return ret;
}

int main() {
    prep();
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            g[i][j] = (c - 'a');
        }
    }
    ll ans = 0;
    for (int l = 0; l < m; ++l) {
        vector<ll> hsh(n);
        memset(cnt, 0, sizeof(cnt));
        for (int r = l; r < m; ++r) {
            for (int i = 0; i < n; ++i) {
                //hsh[i] = (hsh[i] - binpow(p[g[i][r]], cnt[i][g[i][r]]) + M) % M;
                //hsh[i] = (hsh[i] + binpow(p[g[i][r]], ++cnt[i][g[i][r]])) % M;
                hsh[i] = (hsh[i] - p[g[i][r]] * cnt[i][g[i][r]] + M) % M;
                hsh[i] = (hsh[i] + p[g[i][r]] * ++cnt[i][g[i][r]]) % M;
                int ocnt = 0;
                for (int k = 0; k < C; ++k)
                    ocnt += (cnt[i][k] & 1);
                ok[i] = (ocnt <= 1);
            }
            /*
            cout << "L, R: " << l << " " << r << '\n';
            for (int i : hsh)
                cout << i << " ";
            cout << '\n';
            for (int i = 0; i < n; ++i)
                cout << ok[i] << " \n"[i == n - 1];
            */
            int i = 0;
            while (i < n) {
                while (i < n && !ok[i])
                    ++i;
                int j = i;
                vector<ll> cur;
                while (j < n && ok[j]) {
                    cur.push_back(hsh[j]);
                    ++j;
                }
                i = j;
                ans += manacher(cur);
            }
            //cout << "ans now: " << ans << '\n';
        }
    }
    cout << ans << '\n';
}
