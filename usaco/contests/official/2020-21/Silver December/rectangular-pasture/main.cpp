#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
using ll=long long;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=2505;
int n;
ll ans;
pair<int, int> a[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a+n);
    for (int i=0; i<n; ++i) {
        oset<int> s;
        for (int j=i; j<n; ++j) {
            s.insert(a[j].se);
            int tp=a[i].se, btm=a[j].se;
            if (tp<btm)
                swap(tp, btm);
            ll abv=s.size()-s.order_of_key(tp),
               blw=s.order_of_key(btm)+1;
            ans+=abv*blw;
        }
    }
    cout << ans+1 << '\n';
}

