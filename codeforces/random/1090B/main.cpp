#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<pair<int, string>> act;
map<string, int> mp;

int main() {
    string s;
    int f=0, j=0, cnt=0;
    while (getline(cin, s)) {
        if (s[0]=='\\' && s[1]=='b' && !f)
            f=1, act.pb({0, s});
        else if (f) {
            if (s[1]=='e') {
                act.pb({100, s});
                break;
            }
            string c="";
            for (int i=9; s[i]^'}'; ++i)
                c+=s[i];
            act.pb({mp[c], s});
        }
        else {
            for (int i=0; i<s.size(); ++i)
                if (s[i]=='{') {
                    ++i;
                    string c="";
                    while (s[i]^'}')
                        c+=s[i++];
                    mp[c]=++cnt;
                }
        }
    }
    if (is_sorted(act.begin(), act.end()))
        cout << "Correct\n";
    else {
        cout << "Incorrect\n";
        sort(act.begin(), act.end());
        for (auto p:act)
            cout << p.second << '\n';
    }
}

