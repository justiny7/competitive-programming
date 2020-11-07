#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, mx=0, m=0; cin >> n;
        vector<int> cnt(n+1);
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            ++cnt[a];
        }
        for (int i=1; i<=n; ++i) {
            if (cnt[i]>mx)
                mx=cnt[i], m=1;
            else if (cnt[i]==mx)
                ++m;
        }
        cout << m-1+(n-mx*m)/(mx-1) << '\n';
    }
}

