#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, par[2][N];
set<pair<int, int>> s[2]; // s[c] stores all the possible transitions from hand c ^ 1 --> c
bool ans[N];

void trim(int c, int l, int r) {
    while (s[c].size() && prev(s[c].end())->first > r)
        s[c].erase(prev(s[c].end()));
    while (s[c].size() && s[c].begin()->first < l)
        s[c].erase(s[c].begin());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    s[0].emplace(0, 0);
    s[1].emplace(0, 0);

    int lst = 0;
    for (int i = 0; i < n; ++i) {
        bool add[2];
        for (int c = 0; c < 2; ++c)
            add[c] = s[c ^ 1].size();
        for (int c = 0; c < 2; ++c) // if s[c ^ 1] isn't empty, that means that there was a possible transition in the last round on the other hand
            if (add[c])             //   -> we can try adding the last card onto this hand as a transition to the other hand from the last round
                s[c].emplace(lst, i);

        int x, l[2], r[2];
        cin >> x >> l[0] >> r[0] >> l[1] >> r[1];

        for (int c = 0; c < 2; ++c) {
            if (l[c] <= x && x <= r[c]) { // if the current card fits on this hand, trim the possible transitions to fit the other hand
                trim(c, l[c ^ 1], r[c ^ 1]);
                if (s[c].size())                          // there exists a possible transition from the other hand, meaning that from par[c][i + 1] to
                    par[c][i + 1] = s[c].begin()->second; // i + 1 there is a card in the other hand that fits all constraints along that interval
            }
            else // otherwise, clear the possibilities for this hand
                s[c].clear();
        }

        lst = x;
    }

    if (s[0].empty() && s[1].empty())
        cout << "No\n";
    else {
        cout << "Yes\n";

        bool f = s[0].empty();
        int cur = n;
        while (cur) {
            int nxt = par[f][cur];

            for (int i = nxt; i < cur; ++i)
                ans[i] = f;

            f ^= 1, cur = nxt;
        }

        for (int i = 0; i < n; ++i)
            cout << ans[i] << " \n"[i == n - 1];
    }
}
