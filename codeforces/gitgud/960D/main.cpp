#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=61;
int q;
ll cnt[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> q;
    while (q--) {
        ll t, k, x;
        cin >> t >> x;
        int c=0;
        while (x>=(1LL<<c))
            ++c;
        --c;
        if (t<3) {
            cin >> k;
            k=(k%(1LL<<c)+(1LL<<c))%(1LL<<c);
            for (int i=c; i<((t&1)?c+1:mxN); ++i, k<<=1)
                cnt[i]=(cnt[i]+k)%(1LL<<i);
        }
        else {
            x-=(1LL<<c);
            ll pos=(x+cnt[c])%(1LL<<c);
            for (int i=c; ~i; --i, pos>>=1)
                cout << (pos-cnt[i]+(1LL<<i))%(1LL<<i)+(1LL<<i) << " \n"[i==0];
        }
    }
}

