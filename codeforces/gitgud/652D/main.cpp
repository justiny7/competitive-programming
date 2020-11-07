#include <bits/stdc++.h>
#define x first
#define id second
using namespace std;
using pii=pair<int, int>;

const int mxN=2e5+1;
int n, bit[mxN<<1], ans[mxN], lst[mxN];
pii a[mxN<<1];
set<int> s;
map<int, int> mp;

void upd(int i) {
    for (++i; i<mxN<<1; i+=i&-i)
        ++bit[i];
}
int query(int i) {
    int ans=0;
    for (++i; i; i-=i&-i)
        ans+=bit[i];
    return ans;
}
int query(int l, int r) {
    return query(r)-query(l-1);
}

int main() {
    memset(lst, -1, sizeof(lst));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i].x >> a[i+n].x;
        a[i].id=a[i+n].id=i;
        s.insert(a[i].x);
        s.insert(a[i+n].x);
    }
    sort(a, a+(n<<1));
    int c=0;
    for (int i:s)
        mp[i]=c++;
    for (int i=0; i<n<<1; ++i)
        a[i].x=mp[a[i].x];
    for (int i=0; i<n<<1; ++i) {
        if (~lst[a[i].id]) {
            ans[a[i].id]=query(lst[a[i].id], a[i].x);
            upd(lst[a[i].id]);
        }
        else
            lst[a[i].id]=a[i].x;
    }
    for (int i=0; i<n; ++i)
        cout << ans[i] << '\n';
}

