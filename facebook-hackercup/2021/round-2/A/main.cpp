#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> done, need;
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        need.insert(c);
    }

    int ans = 0;
    while (n--) {
        vector<int> here, save_done, save_need;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;

            if (done.find(x) != done.end()) {
                done.erase(done.find(x));
                save_done.push_back(x);
            } else if (need.find(x) != need.end()) {
                need.erase(need.find(x));
                save_need.push_back(x);
            } else {
                here.push_back(x);
            }
        }

        for (int x : here) {
            if (need.size())
                need.erase(need.begin());
            else {
                done.erase(done.begin());
                ++ans;
            }

            save_done.push_back(x);
        }

        for (int i : save_need)
            need.insert(i);
        for (int i : save_done)
            done.insert(i);

        assert(need.size() + done.size() == m);
    }

    cout << ans << '\n';

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

