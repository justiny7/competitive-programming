#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
using namespace std;
using pii=pair<int, int>;
using ll=long long;

const int mxN=2e5+1;
int n, bit[mxN];
map<int, int> pos;
vector<pii> v;
vector<int> v2;

void upd(int i) {
    for (; i<mxN; i+=i&-i)
        ++bit[i];
}
int query(int i) {
    int ret=0;
    for (; i; i-=i&-i)
        ret+=bit[i];
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (!pos.count(a))
            pos[a]=a;
        if (!pos.count(b))
            pos[b]=b;
        swap(pos[a], pos[b]);
    }
    for (pii p:pos)
        v.push_back(p), v2.push_back(p.se);
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    ll ans=0;
    for (int i=v2.size()-1; ~i; --i) {
        int ind=lb(v2.begin(), v2.end(), v[i].se)-v2.begin()+1;
        ans+=(ll)query(ind);
        upd(ind);
    }
    for (int i=0; i<v.size(); ++i) {
        int vhi=max(v[i].fi, v[i].se),
            vlo=min(v[i].fi, v[i].se);
        auto hi=lb(v.begin(), v.end(), pii(vhi, -1)),
             lo=lb(v.begin(), v.end(), pii(vlo+1, -1));
        if (hi==v.begin() || --hi-lo+1<0)
            continue;
        ans+=(ll)(vhi-vlo-1)-(ll)(hi-lo+1);
    }
    cout << ans << '\n';
}

