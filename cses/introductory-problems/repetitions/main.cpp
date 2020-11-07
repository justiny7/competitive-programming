#include <bits/stdc++.h>
using namespace std;

string s;
map<char, int> m;

int main(void) {
    cin >> s;
    int cur=1, ans=-1;
    for (int i=1; i<s.length(); i++) {
        if (s[i]!=s[i-1]) {
            ans=max(ans, cur);
            cur=1;
        }
        else
            cur++;
    }
    ans=max(ans, cur);
    cout << ans << '\n';
}

