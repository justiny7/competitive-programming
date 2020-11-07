#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vl>;

const ll M=1e9+7;
vvl a={{0,1},{1,1}};
ll n;

vvl mult(vvl x, vvl y) {
    vvl ans(2, vl(2));
    for (int i=0; i<2; ++i)
        for (int j=0; j<2; ++j)
            for (int k=0; k<2; ++k)
                ans[i][j]=(ans[i][j]+x[i][k]*y[k][j])%M;
    return ans;
}

vvl bpow(ll k) {
    vvl ans={{1,0},{0,1}};
    while (k) {
        if (k&1)
            ans=mult(ans, a);
        a=mult(a, a), k>>=1;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (!n)
        cout << "0\n";
    else
        cout << bpow(n-1)[1][1] << '\n';
}


