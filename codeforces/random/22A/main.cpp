#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    set<int> s;

    while (n--) {
        int x; cin >> x;
        s.insert(x);
    }

    if (s.size() == 1)
        cout << "NO\n";
    else
        cout << *next(s.begin()) << '\n';
}
