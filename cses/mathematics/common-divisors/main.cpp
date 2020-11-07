#include <bits/stdc++.h>
using namespace std;

const int mxV=1e6;
int n, ans, cnt[mxV+1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        ++cnt[a];
    }
    for (int i=1; i<=mxV; ++i) {
        int c=0;
        for (int j=1; j<=mxV/i; ++j)
            c+=cnt[i*j];
        if (c>1)
            ans=max(ans, i);
    }
    cout << ans << '\n';
}

