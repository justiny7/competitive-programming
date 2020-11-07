#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;

ll a[200001], w[200001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k, ans=0;
        cin >> n >> k;
        for (int i=0; i<n; ++i)
            cin >> a[i];
        for (int i=0; i<k; ++i)
            cin >> w[i];
        sort(w, w+k, greater<ll>());
        sort(a, a+n, greater<ll>());
        int left=k, cur=k-1;
        map<int, pll> mins;
        for (int i=0; i<k; ++i) {
            mins[cur]={a[i], a[i]};
            w[cur]--, cur--;
            if (w[cur+1]==0) {
                left--;
                ans+=2*a[i];
            }
        }
        cur=left-1;
        for (int i=k; i<n; ++i) {
            //cout << "cur " << cur << '\n';
            //cout << w[cur] << '\n';
            while (w[cur]) {
                mins[cur].fi=min(a[i], mins[cur].fi);
                w[cur]--, ++i;
            }
            --i;
            ans+=mins[cur].fi+mins[cur].se;
            left--, cur--;
            //cout << "left: " << left << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}
