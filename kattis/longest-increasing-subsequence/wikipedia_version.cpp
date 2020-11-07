#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n) {
        vector<int> a(n+1), dp(n+1), par(n+1), ans;
        int l=0;
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            int lo=1, hi=l;
            while (lo<=hi) {
                int mid=(lo+hi+1)/2;
                if (a[dp[mid]]<a[i])
                    lo=mid+1;
                else
                    hi=mid-1;
            }
            par[i]=dp[lo-1], dp[lo]=i;
            l=max(l, lo);
        }
        int k=dp[l];
        for (int i=0; i<l; ++i)
            ans.pb(k), k=par[k];
        cout << l << '\n';
        for (int i=ans.size()-1; i>=0; --i) {
            cout << ans[i]-1;
            if (i)
                cout << " ";
        }
        cout << '\n';
    }
}


