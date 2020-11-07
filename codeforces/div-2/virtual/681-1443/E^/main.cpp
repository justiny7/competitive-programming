#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll=long long;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=2e5+1;
ll n, q, mn, cur;
vector<ll> cperm, pref;

vector<ll> kth(ll k) {
    vector<ll> ans(mn), ind(mn);
    for (ll i=1, d=1; i<=mn; ++i) {
        if (!(k/d))
            break;
        ind[mn-i]=(k/d)%i, d*=i;
    }
    oset<ll> s;
    for (ll i=1; i<=mn; ++i)
        s.insert(i);
    for (int i=0; i<mn; ++i) {
        ans[i]=*s.find_by_order(ind[i]);
        s.erase(ans[i]);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    mn=min(n, 15LL);
    for (ll i=1; i<=mn; ++i)
        cperm.push_back(i+max(0LL, n-15));
    pref.push_back(0);
    for (int i=1; i<=n-mn; ++i)
        pref.push_back(i+pref.back());
    while (q--) {
        int t; cin >> t;
        if (t&1) {
            ll l, r, ans=0;
            cin >> l >> r;
            if (n>15) {
                if (r>n-15)
                    for (int i=max(1LL, l-n+15)-1; i<r-n+15; ++i)
                        ans+=cperm[i];
                if (l<=n-15)
                    ans+=pref[min(r, n-15)]-pref[l-1];
            }
            else
                for (int i=l-1; i<r; ++i)
                    ans+=cperm[i];
            cout << ans << '\n';
        }
        else {
            ll x; cin >> x;
            cur+=x;
            cperm=kth(cur);
            if (n>15)
                for (ll &i:cperm)
                    i+=n-15;
        }
    }
}

