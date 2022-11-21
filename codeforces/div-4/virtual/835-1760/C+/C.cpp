#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    multiset<int, greater<>> ms;
    for (int &i : a) {
        cin >> i;
        ms.insert(i);
    }

    for (int i : a) {
        ms.erase(ms.find(i));
        cout << i - *ms.begin() << " ";
        ms.insert(i);
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

