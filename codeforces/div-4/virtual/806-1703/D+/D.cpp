#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    set<string> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        string here = a[i];
        bool f = 0;
        for (int j = 1; j < here.size(); ++j) {
            string st = here.substr(0, j);
            string en = here.substr(j);

            if (s.count(st) && s.count(en)) {
                f = 1;
                break;
            }
        }

        cout << f;
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


