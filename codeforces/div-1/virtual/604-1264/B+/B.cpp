#include <bits/stdc++.h>
using namespace std;

int n, cnt[4];
vector<int> ans;

void check(int a, int b) {
    int c = -1, d = -1;
    for (int i = 0; i < 4; ++i)
        if (i != a && i != b)
            (~c) ? d = i : c = i;

    if (abs(cnt[a] - cnt[b]) == 1 && cnt[c] == 0 && cnt[d] == 0) {
        cout << "YES\n";

        bool f = cnt[a] > cnt[b];
        while (n--) {
            cout << (f ? a : b) << " \n"[n == 0];
            f ^= 1;
        }

        cout << '\n';
        exit(0);
    }
}
void ins(int x) {
    ans.push_back(x);
    --cnt[x];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 4; ++i)
        cin >> cnt[i], n += cnt[i];

    check(0, 1);
    check(1, 2);
    check(2, 3);

    int c1 = cnt[1] - cnt[0], c2 = cnt[2] - cnt[3];

    if (c1 < 0 || c2 < 0 || abs(c1 - c2) > 1)
        cout << "NO\n";
    else {
        cout << "YES\n";

        if (c1 > c2) {
            ans.push_back(1);
            --cnt[1];
        }

        while (cnt[0]) {
            ins(0);
            ins(1);
        }
        while (cnt[2] && cnt[1]) {
            ins(2);
            ins(1);
        }
        while (cnt[3]) {
            ins(2);
            ins(3);
        }

        if (cnt[2])
            ins(2);

        assert(ans.size() == n);
        for (int i = 0; i < n; ++i)
            cout << ans[i] << " \n"[i == n - 1];
    }
}

