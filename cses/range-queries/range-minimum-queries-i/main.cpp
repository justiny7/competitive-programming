#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, q;
ll a[mxN], seg[mxN*4];

void build(int cur=1, int l=0, int r=n-1) {
    if (l==r)
        seg[cur]=a[l];
    else {
        int mid=(l+r)/2;
        build(cur*2, l, mid);
        build(cur*2+1, mid+1, r);
        seg[cur]=min(seg[cur*2], seg[cur*2+1]);
    }
}

ll query(int l, int r, int li=0, int ri=n-1, int i=1) {
    if (l>r)
        return LLONG_MAX;
    if (li==l && ri==r)
        return seg[i];
    int mid=(li+ri)/2;
    return min(query(l, min(r, mid), li, mid, i*2), query(max(mid+1, l), r, mid+1, ri, i*2+1));
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int a, b;
        cin >> a >> b, --a, --b;
        cout << query(a, b) << '\n';
    }
}
