#include <bits/stdc++.h>
using namespace std;
using db=double;

const int mxN=501;
int n, m, c[mxN];
db ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> c[i];
    while (m--) {
        int a, b; db x;
        cin >> a >> b >> x;
        ans=max(ans, (c[a]+c[b])/x);
    }
    cout << setprecision(15) << fixed << ans << '\n';
}

