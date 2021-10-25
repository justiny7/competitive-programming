#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> dq;
    while (n--) {
        int x;
        cin >> x;

        if (dq.empty() || x < dq.front())
            dq.push_front(x);
        else
            dq.push_back(x);
    }

    while (dq.size()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

