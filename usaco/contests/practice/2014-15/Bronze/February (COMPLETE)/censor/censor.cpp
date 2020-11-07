#include <bits/stdc++.h>
using namespace std;

ifstream fin("censor.in");
ofstream fout("censor.out");

string s, t, ans;

int main(void) {
    fin >> s >> t;
    int n=s.size(), x=t.size();
    for (int i=0; i<n; ++i) {
        ans.push_back(s[i]);
        if (ans.size()>=x)
            if (ans.substr(ans.size()-x)==t)
                ans.resize(ans.size()-x);
    }
    fout << ans << '\n';
}
