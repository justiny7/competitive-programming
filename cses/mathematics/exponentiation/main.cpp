#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD=1e9+7;
int n;

int binpow(ll b, ll e) {
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
        ll a, b;
        cin >> a >> b;
        cout << binpow(a, b) << '\n';
    }
}
