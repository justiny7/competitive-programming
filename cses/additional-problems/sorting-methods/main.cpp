#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, a[mxN], bit[mxN];
vector<ll> sz;
bool vis[mxN];

void upd(int i, ll x) {
    for (; i<mxN; i+=i&-i)
        bit[i]+=x;
}
ll query(int i) {
    ll ans=0;
    for (; i; i-=i&-i)
        ans+=bit[i];
    return ans;
}

void dfs(int v) {
    vis[v]=1;
    if (!vis[a[v]])
        ++sz.back(), dfs(a[v]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    ll c=0;
    for (int i=n; i; --i) {
        c+=query(a[i]);
        upd(a[i], 1);
    }
    cout << c << " ";
    for (int i=1; i<=n; ++i)
        if (!vis[i]) {
            sz.pb(1LL);
            dfs(i);
        }
    c=0;
    for (ll i:sz)
        c+=i-1;
    cout << c << " ";
    {
        vector<int> dp;
        for (int i=1; i<=n; ++i) {
            auto it=lower_bound(dp.begin(), dp.end(), a[i]);
            if (it==dp.end())
                dp.pb(a[i]);
            else
                *it=a[i];
        }
        cout << n-dp.size() << " ";
    }
    c=n;
    for (int i=n; i; --i)
        if (a[i]==c)
            --c;
    cout << c << '\n';
}

