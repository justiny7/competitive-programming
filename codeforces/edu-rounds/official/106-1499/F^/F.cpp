#include <bits/stdc++.h>
using namespace std;

//{{{ Mint
const int M = 998'244'353;
struct Mint {
    int val;
    Mint (int _val = 0) : val(_val) {
        val = (-M <= val && val < M) ? val : val % M;
        if (val < 0)
            val += M;
    }
    explicit operator int() const { return val; }
    friend bool operator==(const Mint &a, const Mint &b) { return a.val == b.val; }
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }
    friend bool operator<(const Mint &a, const Mint &b) { return a.val < b.val; }

    Mint &operator+=(const Mint &o) { if ((val += o.val) >= M) val -= M; return *this; }
    Mint &operator-=(const Mint &o) { if ((val -= o.val) < 0) val += M; return *this; }
    Mint &operator*=(const Mint &o) { val = static_cast<int>(static_cast<long long>(val) * o.val % M); return *this; }
    Mint &operator/=(const Mint &o) { return (*this) *= inv(o); }

    friend Mint binpow(Mint a, int b) {
        Mint ret(1);
        for (; b; b >>= 1, a *= a)
            if (b & 1)
                ret *= a;
        return ret;
    }
    friend Mint inv(const Mint &a) { return binpow(a, M - 2); }

    Mint operator-() { return Mint(-val); }
    Mint operator++() { return (*this) += 1; }
    Mint operator--() { return (*this) -= 1; }
    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }

    friend ostream &operator<<(ostream &o, const Mint &m) { o << m.val; return o; }
    friend istream &operator>>(istream &i, Mint &m) { int x; i >> x; m.val = x; return i; }
};
//}}}

const int mxN = 5e3 + 1;
int n, k;
vector<Mint> dp[mxN];
vector<int> adj[mxN];

void dfs(int v = 1, int p = 0) {
    dp[v] = {1};
    for (int u : adj[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        vector<Mint> here(max(dp[v].size(), dp[u].size() + 1));
        for (int i = 0; i < dp[v].size(); ++i) {
            for (int j = 0; j < dp[u].size(); ++j) {
                here[i] += dp[v][i] * dp[u][j];
                if (i + j + 1 <= k)
                    here[max(i, j + 1)] += dp[v][i] * dp[u][j];
            }
        }
        dp[v] = here;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    Mint ans;
    for (Mint m : dp[1])
        ans += m;
    cout << ans << '\n';
}
