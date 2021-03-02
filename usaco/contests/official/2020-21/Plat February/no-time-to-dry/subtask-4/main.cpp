//YESSS FIRST PLAT AK (took 1hr 56 minutes :dead:)
#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1, INF=0x3f3f3f3f;
int n, q, mx, a[mxN];

//For every number C, it adds 1 if the first occurrence X of C >= L is <= R and ok[X] is 0

//{{{ Segtree 
int t[mxN<<1];
void upd(int i, int x) {
    for (t[i+=n]=x; i>1; i>>=1)
        t[i>>1]=min(t[i], t[i^1]);
}
int query(int l, int r) {
    int ret=INF;
    for (l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
        if (l&1)
            ret=min(ret, t[l++]);
        if (r&1)
            ret=min(ret, t[--r]);
    }
    return ret;
}
//}}}

//ones increment everything in the prefix
//zeros incremenet everything up to the last occurrence
vector<pair<int, int>> queries[mxN];
int ans[mxN], bit[mxN], lst[mxN]; //range update point query bit
void rupd(int i, int x) {
    for (++i; i<mxN; i+=i&-i)
        bit[i]+=x;
}
void rupd(int l, int r, int x) {
    rupd(l, x);
    rupd(r+1, -x);
}
int pquery(int i) {
    int ret=0;
    for (++i; i; i-=i&-i)
        ret+=bit[i];
    return ret;
}

int main() {
    memset(t, 0x3f, sizeof(t));
    memset(lst, -1, sizeof(lst));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        upd(i, a[i]);
    }
    for (int i=0; i<q; ++i) {
        int l, r;
        cin >> l >> r, --l, --r;
        queries[r].emplace_back(l, i);
    }
    for (int i=0; i<n; ++i) {
        bool f=0;
        if (~lst[a[i]]) {
            if (query(lst[a[i]], i)<a[i])
                f=1;
        }
        else
            f=1;
        if (f)
            rupd(0, i, 1);
        else
            rupd(lst[a[i]]+1, i, 1);
        lst[a[i]]=i;
        //for (int j=0; j<=i; ++j)
            //cout << pquery(j) << " ";
        //cout << '\n';
        for (auto p:queries[i])
            ans[p.second]=pquery(p.first);
    }
    for (int i=0; i<q; ++i)
        cout << ans[i] << '\n';
}

