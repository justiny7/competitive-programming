#include <bits/stdc++.h>
using namespace std;

int n, a;
set<int> tot;
map<int, int> l, r;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a;
    tot.insert(a);
    for (int i=1; i<n; ++i) {
        cin >> a;
        auto it=tot.upper_bound(a);
        if (it!=tot.end() && !l.count(*it)) {
            cout << *it;
            l[*it]=a;
        }
        else {
            cout << *(--it);
            r[*it]=a;
        }
        cout << " \n"[i==n-1];
        tot.insert(a);
    }
}

