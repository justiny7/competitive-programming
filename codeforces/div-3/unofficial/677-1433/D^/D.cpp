#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int &i:v)
            cin >> i;
        int i=0, j=1;
        for (; v[j]==v[i]; ++j);
        if (j==n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << i+1 << " " << j+1 << '\n';
        for (int k=1; k<n; ++k) {
            if (k==j)
                continue;
            if (v[k]^v[i])
                cout << i+1 << " " << k+1 << '\n';
            else
                cout << j+1 << " " << k+1 << '\n';
        }
    }
}

