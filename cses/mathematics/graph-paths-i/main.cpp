#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vl>;

const int mxN=101;
const ll M=1e9+7;
int n, m, k;
vvl v;

vvl mult(vvl& x, vvl& y) {
    vvl ans(n, vl(n));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            for (int k=0; k<n; ++k)
                ans[i][j]=(ans[i][j]+x[i][k]*y[k][j])%M;
    return ans;
}
vvl bpow() {
    vvl ans(n, vl(n));
    for (int i=0; i<n; ++i)
        ans[i][i]=1;
    while (k) {
        if (k&1)
            ans=mult(ans, v);
        v=mult(v, v), k>>=1;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    v=vvl(n, vl(n));
    while (m--) {
        int a, b;
        cin >> a >> b, --a, --b;
        ++v[a][b];
    }
    cout << bpow()[0][n-1] << '\n';
}

