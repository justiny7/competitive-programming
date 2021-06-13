#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<int> s;
    while (n) {
        if (s.count(n % m)) {
            cout << "NO\n";
            return 0;
        }

        s.insert(n % m);
        n /= m;
    }

    cout << "YES\n";
}
