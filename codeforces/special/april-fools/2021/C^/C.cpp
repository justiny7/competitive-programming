#include <bits/stdc++.h>
using namespace std;

int get(char c) {
    return (c - 'A');
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    bool f = 1;
    string s; cin >> s;
    int n =  s.size();
    for (int i = 2; i < n; ++i)
        if ((get(s[i - 1]) + get(s[i - 2])) % 26 != get(s[i]))
            f = 0;
    cout << (f ? "YES" : "NO") << '\n';
}
