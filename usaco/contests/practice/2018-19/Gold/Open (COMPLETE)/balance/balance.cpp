//Looked at solution
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
ll n, a[mxN*2], a_inv, b_inv, ocnt, ans=LLONG_MAX, s=1, t=1;

ll cnt_inv(bool f=0) {
    int st=0, en=n-1;
    if (f)
        st+=n, en+=n;
    ll icnt=0, c=0;
    for (int i=en; i>=st; --i)
        a[i]?icnt+=c:++c;
    return icnt;
}

int main() {
    ifstream cin("balance.in");
    ofstream cout("balance.out");
    cin >> n;
    for (int i=0; i<n*2; ++i)
        cin >> a[i], ocnt+=a[i];
    for (int g=0; g<2; ++g) {
        ll dif=cnt_inv()-cnt_inv(1);
        ans=min(ans, abs(dif));
        int o=0, z=n, displaced=0;
        ll cost=0;
        for (int k=n-1; k>=0; --k) {
            if (a[k]^t)
                continue;
            dif-=s*(n-k-1), cost+=n-k-1;
            dif+=s*(ocnt-n), ++cost;
            dif+=s*o, cost+=o;
            dif+=s*displaced, cost+=displaced;
            if (++o+displaced>n)
                break;
            while (z<n*2 && o+displaced>z-n) {
                if (a[z]==t) {
                    ll c=s*(n+o+displaced-z);
                    dif+=c, cost+=c/s;
                    ++displaced;
                }
                ++z;
            }
            if (z==n*2)
                break;
            ans=min(ans, cost+abs(dif));
        }
        s=-1, t=0;
    }
    cout << ans << '\n';
}

