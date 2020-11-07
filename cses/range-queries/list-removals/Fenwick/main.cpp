#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//OST on indices
const int mxN=2e5+1;
int n, a[mxN];
vector<ll> bit;

void upd(int i, int x) {
    while (i>0 && i<bit.size())
        bit[i]+=x, i+=i&(-i);
}

ll sum(int i) {
    ll ans=0;
    while (i>0)
        ans+=bit[i], i-=i&(-i);
    return ans;
}

int find(int k) {
    int lo=0, hi=bit.size();
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (sum(mid)>=k)
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bit.resize(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        upd(i, 1);
    }
    for (int i=0; i<n; ++i) {
        if (i)
            cout << " ";
        int q, ans;
        cin >> q;
        ans=find(q);
        cout << a[ans];
        upd(ans, -1);
    }
    cout << '\n';
}
