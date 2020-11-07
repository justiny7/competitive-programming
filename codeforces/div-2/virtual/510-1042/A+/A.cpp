#include <bits/stdc++.h>
using namespace std;

const int mxN=101;
int n, m, a[mxN], cmx, tot;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i], cmx=max(cmx, a[i]), tot+=a[i];
    cout << max(cmx, (tot+m+n-1)/n) << " " << cmx+m << '\n';
}

