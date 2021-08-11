#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 69, D = 1e5 + 30;
int n;
vector<int> add[M];
set<int> rem;

int main() {
    cin >> n;

    while (n--) {
        int l, r;
        cin >> l >> r, l += D, r += D;

        if (l > r)
            swap(l, r);

        add[l].push_back(r);
    }

    vector<int> ans;
    for (int i = 0; i < M; ++i) {
        for (int j : add[i])
            rem.insert(j);

        if (rem.count(i)) {
            ans.push_back(i);
            rem.clear();
        }
    }

    int sz = ans.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; ++i)
        cout << ans[i] - D << " \n"[i == sz - 1];
}

