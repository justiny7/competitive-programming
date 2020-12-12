#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, a[mxN], xx;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], xx^=a[i];
    if (n%2==0 && xx)
        return cout << "NO\n", 0;
    vector<array<int, 3>> ops;
    for (int i=1; i+2<=n; i+=2)
        ops.push_back({i, i+1, i+2});
    for (int i=1; i+2<=n; i+=2)
        ops.push_back({i, i+1, n});
    cout << "YES\n" << ops.size() << '\n';
    for (auto p:ops)
        cout << p[0] << " " << p[1] << " " << p[2] << '\n';
}

