#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int a[mxN];

bool cmp(int x, int y) {
    return a[x]<a[y];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        vector<int> dp, par(n+1), ans;
        dp.pb(0);
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            int ind=lower_bound(dp.begin()+1, dp.end(), i, cmp)-dp.begin();
            if (ind==dp.size())
                par[i]=dp.back(), dp.pb(i);
            else
                par[i]=dp[ind-1], dp[ind]=i;
        }
        int sz=dp.size()-1, k=dp.back();
        for (int i=0; i<sz; ++i)
            ans.pb(k), k=par[k];
        cout << sz << '\n';
        for (int i=sz-1; ~i; --i) {
            cout << ans[i]-1;
            if (i)
                cout << " ";
        }
        cout << '\n';
    }
}


