#include <bits/stdc++.h>
using namespace std;

int n, m, lst = -1;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    while (n--) {
        string s;
        cin >> s;

        if (s[0] == lst || count(s.begin(), s.end(), s[0]) != m) {
            cout << "NO\n";
            return 0;
        }
        
        lst = s[0];
    }

    cout << "YES\n";
}

