#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int res = 0;
    multiset<int> s;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    while (s.size()) {
        auto it = s.upper_bound(res);
        if (it != s.end()) {
            s.erase(it);
            ++res;
        } else {
            break;
        }
    }

    cout << res << '\n';
}

