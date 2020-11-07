#include <bits/stdc++.h>
using namespace std;

string s;
map<char, int> freq;
vector<char> e, o;

int main(void) {
    cin >> s;
    for (int i=0; i<s.length(); ++i)
        freq[s[i]]++;
    for (auto p : freq) {
        if (p.second&1)
            o.push_back(p.first);
        else
            e.push_back(p.first);
    }
    if (!(s.length()&1) && !o.empty())
        cout << "NO SOLUTION\n";
    else if (s.length()&1 && o.size()!=1)
        cout << "NO SOLUTION\n";
    else {
        string ans="";
        for (char c : e)
            for (int i=0; i<freq[c]/2; ++i)
                ans+=c;
        string t=ans;
        reverse(t.begin(), t.end());
        if (s.length()&1)
            for (int i=0; i<freq[o[0]]; ++i)
                ans+=o[0];
        ans+=t;
        cout << ans << '\n';
    }
}
