#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, d, o;
    cin >> n >> x >> y, d = n - y;

    vector<int> b(n);
    for (int &i : b)
        cin >> i;

    vector<vector<int>> pos(n + 2);
    for (int i = 0; i < n; ++i)
        pos[b[i]].push_back(i);

    priority_queue<array<int, 2>> pq;
    for (int i = 1; i <= n + 1; ++i) {
        if (pos[i].size())
            pq.push({(int)pos[i].size(), i});
        else
            o = i;
    }

    vector<int> ans(n);
    for (int i = 0; i < x; ++i) {
        auto [sz, col] = pq.top();
        pq.pop();

        ans[pos[col].back()] = col;
        pos[col].pop_back();

        if (pos[col].size())
            pq.push({sz - 1, col});
    }

    /*
    cout << "now ans:\n";
    for (int i : ans)
        cout << i << " ";
    cout << '\n';
    */

    int left = n - x, mx = 2 * (pq.size() ? pq.top()[0] : 0) - left;
    if (mx > d) {
        cout << "NO\n";
        return;
    }

    vector<int> remain, rot;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j < pos[i].size(); ++j)
            remain.push_back(pos[i][j]);
        pos[i].clear();
    }

    rot = remain;
    rotate(rot.begin(), rot.begin() + left / 2, rot.end());

    /*
    cout << "remain:\n";
    for (auto i : remain)
        cout << i << " ";
    cout << '\n';
    */

    cout << "YES\n";
    for (int i = 0; i < left; ++i) {
        int j = remain[i];
        ans[j] = b[rot[i]];
        if (ans[j] == b[j])
            ans[j] = o, --d;
    }
    for (int i : remain) {
        if (!d)
            break;
        if (ans[i] != o)
            ans[i] = o, --d;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

