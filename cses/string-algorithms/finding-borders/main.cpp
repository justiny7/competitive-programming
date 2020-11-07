#include <bits/stdc++.h>
using namespace std;

const int mxN=1e6+1;
string s;
int n, z[mxN];
vector<int> ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size();
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i<=r)
            z[i]=min(r-i+1, z[i-l]);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]])
            ++z[i];
        if (i+z[i]>r)
            l=i, r=i+z[i]-1;
        if (z[i]==n-i)
            ans.push_back(n-i);
    }
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); ++i)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

