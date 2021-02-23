#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e6+1;
const ll M=1e9+7;
int n, k, spf[mxN];
ll ans, tot, p[mxN], u[mxN];
vector<int> factors[mxN];

void sieve() {
    for (ll i=2; i<mxN; ++i) {
        if (!spf[i]) {
            spf[i]=i;
            for (ll j=i*i; j<mxN; j+=i)
                if (!spf[j])
                    spf[j]=i;
        }
    }
}
void mobius() {
    for (int i=1; i<mxN; ++i) {
        for (int j=i; j<mxN; j+=i)
            factors[j].push_back(i);
        int cur=i, c=0;
        while (cur>1) {
            int nxt=cur/spf[cur];
            if (spf[nxt]==spf[cur])
                break;
            ++c;
            cur=nxt;
        }
        if (cur==1)
            u[i]=(c&1)?-1:1;
    }
}
ll binpow(ll a, ll b) {
    ll ret=1;
    while (b) {
        if (b&1)
            (ret*=a)%=M;
        (a*=a)%=M, b>>=1;
    }
    return ret;
}

int main() {
    sieve();
    mobius();
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=k; ++i)
        p[i]=binpow(i, n);
    for (int i=1; i<=k; ++i) {
        //cout << "factors of " << i << '\n';
        for (auto j:factors[i]) {
            //cout << j << " ";
            tot-=(u[j]*p[(i-1)/j]);
            tot+=(u[j]*p[i/j]);
        }
        ((tot%=M)+=M)%=M;
        //cout << '\n' << tot << '\n';
        (ans+=(tot^i))%=M;
    }
    cout << ans << '\n';
}

