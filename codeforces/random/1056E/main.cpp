#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Hash {{{
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 69;
const ll M1 = 1e9 + 7, M2 = 1e9 + 9, B = uid(501, M1 - 2);
ll p1[N], p2[N], inv1[N], inv2[N];

ll binpow(ll a, ll b, ll MOD) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            (ret *= a) %= MOD;
        (a *= a) %= MOD, b >>= 1;
    }
    return ret;
}
void prep() {
    p1[0] = p2[0] = inv1[0] = inv2[0] = 1;
    for (int i = 1; i < N; ++i) {
        p1[i] = p1[i - 1] * B % M1;
        p2[i] = p2[i - 1] * B % M2;
        inv1[i] = binpow(p1[i], M1 - 2, M1);
        inv2[i] = binpow(p2[i], M2 - 2, M2);
    }
}

struct Hash {
    vector<ll> hsh1, hsh2;
    Hash(string s) {
        int sz = s.size();
        hsh1.resize(sz + 1), hsh2.resize(sz + 1);
        for (int i = 0; i < sz; ++i) {
            hsh1[i + 1] = (hsh1[i] + s[i] * p1[i]) % M1;
            hsh2[i + 1] = (hsh2[i] + s[i] * p2[i]) % M2;
        }
    }
    pair<ll, ll> get(int st, int len) {
        int en = st + len;
        ll ret1 = (((hsh1[en] - hsh1[st]) * inv1[st] % M1) + M1) % M1,
           ret2 = (((hsh2[en] - hsh2[st]) * inv2[st] % M2) + M2) % M2;
        return {ret1, ret2};
    }
};
//}}}

int n, m, ans;
string s, t;

int main() {
    prep();
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t;
    n = s.size(), m = t.size();
    int zc = count(s.begin(), s.end(), '0'),
        oc = n - zc;
    Hash ht(t);
    for (int i = 1; i <= m / zc; ++i) {
        if ((m - i * zc) % oc)
            continue;
        int j = (m - i * zc) / oc;
        if (j == 0)
            continue;
        assert(zc * i + oc * j == m);
        pair<ll, ll> ohsh = {-1, -1}, zhsh = {-1, -1};
        bool f = 1;
        for (int k = 0, c = 0; k < n; ++k) {
            if (s[k] == '0') {
                if (zhsh.first < 0)
                    zhsh = ht.get(c, i);
                else if (ht.get(c, i) != zhsh)
                    f = 0;
                c += i;
            }
            else {
                if (ohsh.first < 0)
                    ohsh = ht.get(c, j);
                else if (ht.get(c, j) != ohsh)
                    f = 0;
                c += j;
            }
        }
        if (f && ohsh != zhsh)
            ++ans;
    }
    cout << ans << '\n';
}
