#include <bits/stdc++.h>
using namespace std;

int n, m, t;
multiset<int> h;

int main(void) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        h.insert(a);
    }
    for (int i=0; i<m; i++) {
        cin >> t;
        if (h.size() == 0) {
            cout << "-1\n";
            continue;
        }
        auto ans=h.upper_bound(t);
        if (ans==h.begin()) {
            cout << "-1\n";
            continue;
        }
        cout << *(--ans) << '\n';
        h.erase(ans);
    }
}

