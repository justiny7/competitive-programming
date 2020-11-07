#include <bits/stdc++.h>
using namespace std;

int x, n;
multiset<int, greater<int>> l;
set<int> s;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    l.insert(x);
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        auto u=s.upper_bound(a), b=s.lower_bound(a);
        --b;
        l.erase(l.find(*u-*b));
        l.insert(*u-a);
        l.insert(a-*b);
        s.insert(a);
        //cout << *u << " " << *b << '\n';
        if (i>0)
            cout << " ";
        cout << *l.begin();
    }
    cout << '\n';
}
