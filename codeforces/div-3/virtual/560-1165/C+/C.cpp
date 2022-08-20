#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int rem = 0;
    string res;
    for (int i = 0; i < n; ++i) {
        if (res.size() % 2 == 0 || res.back() != s[i])
            res += s[i];
        else
            ++rem;
    }

    if (res.size() & 1)
        res.pop_back(), ++rem;

    cout << rem << '\n' << res << '\n';
}
