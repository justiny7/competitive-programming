#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    int cur=0, tot=0;
    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        int n=s.size();
        tot+=n;
        for (int i=1; i<n-1;) {
            ++cur;
            if (s[i++]=='\\')
                i+=(s[i]^'x'?1:3);
        }
    }
    cout << tot-cur << '\n';
}

