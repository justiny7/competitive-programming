#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1, mxN2=5e3+1, INF=0x3f3f3f3f;
int n, q, mx, a[mxN];

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

//{{{ Subtask 2 
int lst2[mxN2];
int sub2(int l, int r) {
    memset(lst2, -1, sizeof(lst2));
    int ret=0;
    for (int i=l; i<=r; ++i) {
        if (~lst2[a[i]]) {
            if (query(lst2[a[i]], i)<a[i])
                ++ret;
        }
        else
            ++ret;
        lst2[a[i]]=i;
    }
    return ret;
}
//}}}

//{{{ Subtask 3 
const int mxV=11;
int pref[mxN];
bool ok[mxN];
vector<int> occ[mxV];
void precomp() {
    int lst[mxV];
    memset(lst, -1, sizeof(lst));
    for (int i=0; i<n; ++i) {
        occ[a[i]].push_back(i);
        if (~lst[a[i]])
            pref[i]=ok[i]=(query(lst[a[i]], i)<a[i]);
        else
            pref[i]=ok[i]=1;
        if (i)
            pref[i]+=pref[i-1];
        lst[a[i]]=i;
    }
    //for (int i=0; i<n; ++i)
        //cout << pref[i] << " ";
    //cout << '\n';
}
int sub3(int l, int r) {
    int ret=pref[r];
    if (l)
        ret-=pref[l-1];
    //cout << "ret before: " << ret << '\n';
    for (int col=1; col<=mx; ++col) {
        auto it=lower_bound(occ[col].begin(), occ[col].end(), l);
        //cout << col << " " << (it==occ[col].end()?"n/a":to_string(*it)) << '\n';
        if (it!=occ[col].end() && *it<=r && !ok[*it])
            ++ret;
    }
    return ret;
}
//}}}

int main() {
    memset(t, 0x3f, sizeof(t));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        upd(i, a[i]);
        mx=max(mx, a[i]);
    }
    if (mx<=10)
        precomp();
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (mx<=10)
            cout << sub3(l-1, r-1) << '\n';
        else
            cout << sub2(l-1, r-1) << '\n';
    }
}

