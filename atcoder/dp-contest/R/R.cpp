#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vl>;

const int mxN=51;
const ll M=1e9+7;
int n;
ll k;
vvl mat;

vvl mult(vvl &a, vvl &b) {
    vvl ans(n, vl(n));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            for (int k=0; k<n; ++k)
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%M;
    return ans;
}
vvl binpow() {
    vvl ans(n, vl(n));
    for (int i=0; i<n; ++i)
        ans[i][i]=1;
    while (k) {
        if (k&1)
            ans=mult(ans, mat);
        mat=mult(mat, mat), k>>=1;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    mat.resize(n, vl(n));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> mat[i][j];
    vvl ret=binpow();
    ll ans=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            ans=(ans+ret[i][j])%M;
    cout << ans << '\n';
}

