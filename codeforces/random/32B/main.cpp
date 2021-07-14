#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s, n = s.size();

    while (s.size()) {
        if (s[0] == '.') {
            cout << 0;
            s.erase(s.begin());
        }
        else if (s[1] == '.') {
            cout << 1;
            s.erase(s.begin());
            s.erase(s.begin());
        }
        else {
            cout << 2;
            s.erase(s.begin());
            s.erase(s.begin());
        }
    }

    cout << '\n';
}
