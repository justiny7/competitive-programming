#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    int ans=0;
    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        int n=s.size(), i=0, a=0, b=0, cnt=0;
        char c;
        for (; s[i]^'-'; ++i)
            a=a*10+(s[i]-'0');
        for (++i; s[i]^' '; ++i)
            b=b*10+(s[i]-'0');
        c=s[++i];
        string x=s.substr(i+3);
        if ((x[a-1]==c)^(x[b-1]==c))
            ++ans;
    }
    cout << ans << '\n';
}

