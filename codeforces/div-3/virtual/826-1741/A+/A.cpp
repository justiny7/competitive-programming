#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int a, b;
    if (s.back() == t.back()) {
        a = count(s.begin(), s.end(), 'X'),
        b = count(t.begin(), t.end(), 'X');

        if (s.back() == 'S')
            a *= -1, b *= -1;
    } else {
        a = (s.back() == 'L' ? 2 : (s.back() == 'M' ? 1 : 0)),
        b = (t.back() == 'L' ? 2 : (t.back() == 'M' ? 1 : 0));
    }

    if (a < b)
        cout << "<";
    else if (a > b)
        cout << ">";
    else
        cout << "=";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

