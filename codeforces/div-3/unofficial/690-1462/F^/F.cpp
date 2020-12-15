#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, ans=INT_MAX; cin >> n;
        vector<int> lpts(n), rpts(n), l(n), r(n);
        for (int i=0; i<n; ++i) {
            cin >> lpts[i] >> rpts[i];
            l[i]=lpts[i], r[i]=rpts[i];
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        for (int i=0; i<n; ++i) {
            int cur=lower_bound(r.begin(), r.end(), lpts[i])-r.begin()+
                    l.end()-upper_bound(l.begin(), l.end(), rpts[i]);
            ans=min(ans, cur);
        }
        cout << ans << '\n';
    }
}

