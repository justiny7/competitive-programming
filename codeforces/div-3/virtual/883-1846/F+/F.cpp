#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }

    do {
        cout << "- 0" << endl;
        
        b.clear();
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            ++b[v[i]];
        }
    } while (b == a);

    int stay = -1;
    for (int i = 1; i <= 9; ++i)
        if (b[i] > a[i])
            stay = i;

    vector<int> rem;
    for (int i = 0; i < n; ++i)
        if (v[i] != stay)
            rem.push_back(i);

    bool fst = 1;
    n -= rem.size();
    while (true) {
        if (fst) {
            cout << "- " << rem.size();
            for (int i : rem)
                cout << " " << i + 1;
            cout << endl;
            fst = 0;
        } else {
            cout << "- 0" << endl;
        }

        vector<int> lst(n);
        for (int i = 0; i < n; ++i)
            cin >> lst[i];

        for (int i = 0; i < n; ++i) {
            if (lst[i] != stay) {
                cout << "! " << i + 1 << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

