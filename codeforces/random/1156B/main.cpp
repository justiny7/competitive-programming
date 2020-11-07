#include <bits/stdc++.h>
using namespace std;

bool par[256];

int main() {
    for (int i=0; i<26; ++i)
        par['a'+i]=i&1;
    cin.tie(0)->sync_with_stdio(0);
    int t;
    for (cin >> t; t--;) {
        string s; cin >> s;
        multiset<char> o, e;
        for (char c:s) {
            if (par[c])
                o.insert(c);
            else
                e.insert(c);
        }
        if (o.size() && e.size() &&
            abs(*o.rbegin()-*e.begin())==1 &&
            abs(*e.rbegin()-*o.begin())==1)
            cout << "No answer\n";
        else if (o.size() && e.size() &&
            abs(*o.rbegin()-*e.begin())==1) {
            for (char c:e)
                cout << c;
            for (char c:o)
                cout << c;
            cout << '\n';
        }
        else {
            for (char c:o)
                cout << c;
            for (char c:e)
                cout << c;
            cout << '\n';
        }
    }
}


