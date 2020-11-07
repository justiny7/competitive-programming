#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, a[mxN], seg[mxN*4];

void upd(int ind, int x, int l=0, int r=n-1, int v=1) {
    if (l==r)
        seg[v]=x;
    else {
        int mid=(l+r)/2;
        if (ind<=mid)
            upd(ind, x, l, mid, v*2);
        else
            upd(ind, x, mid+1, r, v*2+1);
        seg[v]=seg[v*2]+seg[v*2+1];
    }
}

int query(int l, int r, int li=0, int ri=n-1, int v=1) {
    if (l>ri || r<li)
        return 0;
    if (li>=l && ri<=r)
        return seg[v];
    int mid=(li+ri)/2;
    return query(l, r, li, mid, v*2)+query(l, r, mid+1, ri, v*2+1);
}

void add(int ind) {
    upd(ind, 1);
}

void del(int ind) {
    upd(ind, 0);
}

int get_kth(int k) {
    int lo=0, hi=n-1;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (query(0, mid)>=k)
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], add(i);
    for (int t=0; t<n; ++t) {
        if (t)
            cout << " ";
        int k, ans; cin >> k;
        ans=get_kth(k);
        cout << a[ans];
        del(ans);
    }
    cout << '\n';
}
