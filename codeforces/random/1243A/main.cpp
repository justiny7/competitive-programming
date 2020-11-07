#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, mn=INT_MAX;
        cin >> n;
        vector<int> a(n);
        for (int& i:a)
            cin >> i;
        sort(a.begin(), a.end());
        int ans=1;
        for (int i=1; i<=n; ++i)
            if (a[n-i]>=i)
                ans=i;
        cout << ans << '\n';
    }
}

