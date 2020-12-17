#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    string s; cin >> s;
    int ans=0;
    for (char c:s)
        ans+=(c=='('?1:-1);
    cout << ans << '\n';
}

