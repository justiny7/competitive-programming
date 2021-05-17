#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 21, C = 5e4 + 69 ;
const ll M = 998244353;
int n, m, d[N][C];
ll fact[N];

ll binpow(ll b, ll e) {
    ll ret = 1;
    for (; e; (b *= b) %= M, e >>= 1)
        if (e & 1)
            (ret *= b) %= M;
    return ret;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = (fact[i - 1] * i) % M;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> d[i][j];
    ll tot = 0;
    for (int i = 0; i < m; ++i) { //# of permutations in which the i'th city is controlled?
        vector<int> srt(n);
        for (int j = 0; j < n; ++j)
            srt[j] = d[j][i];
        sort(srt.begin(), srt.end());
        ll here = 1;
        for (int i = 0; i < n; ++i)
            (here *= (srt[i] - 1 - i)) %= M;
        (tot += (fact[n] - here + M) % M) %= M;
    }
    cout << (tot * binpow(fact[n], M - 2)) % M << '\n';
}
