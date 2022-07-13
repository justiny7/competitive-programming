#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> en(n);
    for (int &i : en)
        cin >> i;

    for (int i = 0; i < n; ++i) {
        int sz;
        cin >> sz;

        string s;
        cin >> s;

        int mv = 0;
        for (char c : s)
            mv += (c == 'U' ? -1 : +1);

        en[i] += mv;
        if (en[i] > 9)
            en[i] -= 10;
        if (en[i] < 0)
            en[i] += 10;

        cout << en[i] << " \n"[i == n - 1];
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


