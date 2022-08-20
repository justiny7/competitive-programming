#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    int res = 0;
    for (int i = 0; i < x; ++i) {
        if (i == y)
            res += s[i] == '0';
        else
            res += s[i] == '1';
    }

    cout << res << '\n';

}

