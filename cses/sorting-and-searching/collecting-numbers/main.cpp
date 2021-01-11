#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, ans, pos[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        pos[x]=i;
    }
    for (int i=1; i<n; ++i)
        ans+=(pos[i]>pos[i+1]);
    cout << ans+1 << '\n';
}

