#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1)
            cout << "1\n";
        else if (n == 2)
            cout << "-1\n";
        else {
            for (int i = 1; i <= n; ++i) {
                vector<int> v;
                for (int j = i; j <= n * n; j += n)
                    v.push_back(j);
                rotate(v.begin(), v.begin() + i - 1, v.end());
                for (int j = 0; j < n; ++j)
                    cout << v[j] << " \n"[j == n - 1];
            }
        }
    }
}
