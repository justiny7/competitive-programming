#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;

    if (x == 1) {
        cout << "1\n";
        return;
    }

    int sum = 0;
    string s = to_string(x);
    for (char c : s)
        sum += c - '0';

    reverse(s.begin(), s.end());
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0, p = 1; i < s.size(); ++i, p *= 10) {
        while (pq.size() + 1 < n && s[i] > '0') {
            pq.push(p);
            --s[i];
        }

        if (pq.size() + 1 == n) {
            int lst = 0;
            for (int j = s.size() - 1; ~j; --j)
                lst = lst * 10 + (s[j] - '0');

            if (lst) {
                pq.push(lst);
                break;
            }
        }
    }

    int ones = 0;
    while (pq.size() + ones < n) {
        int tp = pq.top();
        pq.pop();

        if (tp == 1) {
            ++ones;
            continue;
        }

        int cur = tp;
        while (pq.size() + ones + 1 < n && cur > 0) {
            pq.push(tp / 10);
            cur -= tp / 10;
        }

        if (pq.size() + ones + 1 == n && cur > 0) {
            pq.push(cur);
            break;
        }
    }

    while (pq.size()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    while (ones--)
        cout << "1 ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

