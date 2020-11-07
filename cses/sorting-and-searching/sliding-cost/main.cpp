#include <bits/stdc++.h>
#define fi first
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=2e5+1;
int n, k;
ll a[mxN], lsum, rsum;
set<pll> l, r;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        if (i>=k) {
            if (l.count({a[i-k], i-k}))
                l.erase({a[i-k], i-k}), lsum-=a[i-k];
            else
                r.erase({a[i-k], i-k}), rsum-=a[i-k];
        }
        l.insert({a[i], i});
        lsum+=a[i];
        pll last=*l.rbegin();
        if (l.size()>r.size()+1) {
            lsum-=last.fi, rsum+=last.fi;
            r.insert(last);
            l.erase(last);
        }
        while (!r.empty() && !l.empty() && *r.begin()<*l.rbegin()) {
            pll rbeg=*r.begin(), lend=*l.rbegin();
            r.insert(lend);
            r.erase(rbeg);
            l.erase(lend);
            l.insert(rbeg);
            lsum+=(rbeg.fi-lend.fi), rsum+=(lend.fi-rbeg.fi);
        }
        ll med=l.rbegin()->first;
        if (i>=k-1) {
            cout << rsum-(r.size()*med)+(l.size()*med)-lsum;
            if (i<n-1)
                cout << " ";
        }
    }
    cout << '\n';
}
