//YES worked second try b/c I moduloed everything except the answer xd
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ifstream fin("poetry.in");
ofstream fout("poetry.out");

const int mxN=5e3+1, mxK=5e3+1, M=1e9+7;
int n, m, k, s[mxN], c[mxN], dp[mxK][mxN], sum[mxK];
map<char, int> scheme;
ll ans;

ll binpow(ll a, ll b) {
    ll x=1;
    while (b) {
        if (b&1)
            x=x*a%M;
        a=a*a%M, b>>=1;
    }
    return x;
}

int main() {
    fin >> n >> m >> k;
    for (int i=0; i<n; ++i)
        fin >> s[i] >> c[i];
    for (int i=0; i<m; ++i) {
        char c; fin >> c;
        ++scheme[c];
    }
    sum[0]=1;
    for (int i=0; i<=k; ++i)
        for (int j=0; j<n; ++j)
            if (i>=s[j]) {
                dp[i][c[j]]=(dp[i][c[j]]+sum[i-s[j]])%M;
                sum[i]=(sum[i]+sum[i-s[j]])%M;
            }
    for (auto& p:scheme) {
        ll c=0;
        for (int i=1; i<=n; ++i)
            c=(c+binpow(dp[k][i], p.second))%M;
        if (!ans)
            ans=c;
        else
            ans=(ans*c)%M;
    }
    fout << ans << '\n';
}

