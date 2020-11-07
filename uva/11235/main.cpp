#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, q, a[mxN], freq[mxN], seg[4*mxN];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r)
        seg[v]=freq[l];
    else {
        int mid=(l+r)/2;
        build(v*2, l, mid);
        build(v*2+1, mid+1, r);
        seg[v]=max(seg[v*2], seg[v*2+1]);
    }
}

int query(int l, int r, int li=0, int ri=n-1, int v=1) {
    if (l>ri || r<li)
        return 0;
    if (li>=l && ri<=r)
        return seg[v];
    int mid=(li+ri)/2;
    return max(query(l, r, li, mid, v*2), query(l, r, mid+1, ri, v*2+1));
}

int main(void) {
    while (scanf("%d", &n)!=EOF) {
        if (!n)
            break;
        scanf("%d", &q);
        map<int, int> cnt;
        for (int i=0; i<n; ++i)
            scanf("%d", &a[i]), ++cnt[a[i]];
        for (int i=0; i<n; ++i)
            freq[i]=cnt[a[i]];
        memset(seg, 0, sizeof(seg));
        build();
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r), --l, --r;
            if (a[l]==a[r])
                printf("%d\n", r-l+1);
            else {
                int lo=upper_bound(a, a+n, a[l])-a-1,
                    hi=lower_bound(a, a+n, a[r])-a,
                    mid=-1;
                if (lo+1!=hi)
                    mid=query(lo+1, hi-1);
                printf("%d\n", max({lo-l+1, r-hi+1, mid}));
            }
        }
    }
}
