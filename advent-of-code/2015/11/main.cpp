#include <bits/stdc++.h>
#define pb push_back
using namespace std;

string inc(string &s) {
    string ret;
    int n=s.size(), c=1;
    for (int i=n-1; ~i; --i) {
        if (c) {
            if (s[i]=='z')
                ret.pb('a'), c=1;
            else
                ret.pb(s[i]+1), c=0;
        }
        else
            ret.pb(s[i]), c=0;
    }
    if (c)
        ret.pb('a');
    reverse(ret.begin(), ret.end());
    return ret;
}
bool ok(string s) {
    int n=s.size();
    bool f=0, f2=1; int f3=0;
    for (int i=0; i<n-2; ++i)
        f|=(s[i]+1==s[i+1] && s[i+1]+1==s[i+2]);
    for (int i=0; i<n; ++i)
        f2&=((s[i]^'i') && (s[i]^'o') && (s[i]^'l'));
    for (int i=0; i<n-1; ++i)
        if (s[i]==s[i+1])
            ++f3, s[i]=s[i+1]='$';
    return (f && f2 && (f3>1));
}

int main() {
    string cur="vzbxkghb";
    while (!ok(cur))
        cur=inc(cur);
    cout << cur << '\n';
    //part 2
    do {
        cur=inc(cur);
    } while (!ok(cur));
    cout << cur << '\n';
}

