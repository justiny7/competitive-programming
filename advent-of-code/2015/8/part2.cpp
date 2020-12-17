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
        tot+=n, cur+=2;
        for (int i=0; i<n; ++i)
            cur+=((s[i]=='\"' || s[i]=='\\')?2:1);
    }
    cout << cur-tot << '\n';
}

