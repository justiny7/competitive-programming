#include <bits/stdc++.h>
using namespace std;

int n, ans;
multiset<int> k;

int main(void) {
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        if (k.empty()) {
            k.insert(a);
            continue;
        }
        auto it=k.upper_bound(a);
        if (it!=k.end())
            k.erase(it);
        k.insert(a);
    }
    cout << k.size() << '\n';
}

