#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vl>;

const ll M=1e9+7;
ll n, m;
vvl mat;

vvl mult(vvl& x, vvl& y) {
    vvl ans(m, vl(m));
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            for (int k=0; k<m; ++k)
                ans[i][j]=(ans[i][j]+x[i][k]*y[k][j])%M;
    return ans;
}

vvl bpow(vvl& a, ll k) {
    vvl ans(m, vl(m));
    for (int i=0; i<m; ++i)
        ans[i][i]=1;
    while (k) {
        if (k&1)
            ans=mult(ans, a);
        a=mult(a, a), k>>=1;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    if (n<m)
        return cout << "1\n", 0;
    mat=vvl(m, vl(m));
    mat[0][0]=mat[0][m-1]=1;
    for (int i=1; i<m; ++i)
        mat[i][i-1]=1;
    vvl p=bpow(mat, n-m+1);
    ll ans=0;
    for (int i=0; i<m; ++i)
        ans=(ans+p[0][i])%M;
    cout << ans << '\n';
}

