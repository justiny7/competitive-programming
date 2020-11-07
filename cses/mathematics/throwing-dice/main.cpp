#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vl>;

const ll M=1e9+7;
ll k, n=6;
vvl a(6, vl(6));

vvl mult(vvl x, vvl y) {
    vvl ans(6, vl(6));
    for (int i=0; i<6; ++i)
        for (int j=0; j<6; ++j)
            for (int k=0; k<6; ++k)
                ans[i][j]=(ans[i][j]+x[i][k]*y[k][j])%M;
    return ans;
}

vvl bpow() {
    vvl ans(6, vl(6));
    for (int i=0; i<6; ++i)
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
    cin >> k;
    for (int i=0; i<6; ++i)
        a[0][i]=1;
    for (int i=1; i<6; ++i)
        a[i][i-1]=1;
    cout << bpow()[0][0] << '\n';
}

