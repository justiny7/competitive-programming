#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<char> d;
    while (n--) {
        char c;
        cin >> c;
        d.push_back(c);
    }

    while (d.size() > 1) {
        if (d.front() != d.back()) {
            d.pop_front();
            d.pop_back();
        } else {
            break;
        }
    }

    cout << d.size() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

