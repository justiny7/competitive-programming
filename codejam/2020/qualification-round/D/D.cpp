#include <bits/stdc++.h>
using namespace std;

int n, t;

char query(int x) {
    ++t;
    cout << x+1 << endl;
    char ret; cin >> ret;
    return ret;
}
void inv(string &x) {
    for (char &c:x)
        if (c!='-')
            c^=1;
}
void rev(string &x) {
    reverse(x.begin(), x.end());
}

void solve() {
    string s(n, '-');
    int same=-1, dif=-1, cur=0;
    t=1;
    while (t<=150) {
        if (t%10==1 && t>1) {
            for (int i=0; i<n; ++i) {
                if (s[i]=='-' || s[n-i-1]=='-')
                    break;
                if (same<0 && s[i]==s[n-i-1])
                    same=i;
                if (dif<0 && s[i]!=s[n-i-1])
                    dif=i;
            }
            if (~same && ~dif) {
                char nsame=query(same), ndif=query(dif);
                if (nsame==s[same] && ndif!=s[dif])
                    rev(s);
                else if (nsame!=s[same] && ndif==s[dif]) {
                    rev(s);
                    inv(s);
                }
                else if (nsame!=s[same] && ndif!=s[dif])
                    inv(s);
            }
            else {
                query(0); //throw a query away
                char q=query(0);
                if (q!=s[0])
                    inv(s);
            }
        }
        if (s[cur]=='-')
            s[cur]=query(cur);
        else {
            s[n-cur-1]=query(n-cur-1);
            ++cur;
        }
        bool f=0;
        for (char c:s)
            f|=(c=='-');
        if (!f)
            break;
    }
    cout << s << endl;
    char ret; cin >> ret;
    if (ret=='N')
        exit(0);
}

int main() {
    int t; cin >> t >> n;
    while (t--)
        solve();
}

