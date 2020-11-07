#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M=1e9+7;
int n;

ll binpow(ll b, ll e, ll MOD) {
    ll ans=1;
    while (e>0) {
        if (e&1)
            ans=(ans*b)%MOD;
        e>>=1;
        b=(b*b)%MOD;
    }
    return ans%MOD;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, M-1), M) << '\n';
    }
}

