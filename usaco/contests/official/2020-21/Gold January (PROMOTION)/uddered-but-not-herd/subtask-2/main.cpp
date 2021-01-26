#include <bits/stdc++.h>
using namespace std;

const int mxN=20;
int n, same, ans=INT_MAX, dp[1<<mxN], mp[26][26]; //dp[msk] = min cost with msk as letters so far
string s;
vector<int> lets;
set<char> ss;

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size();
    for (int i=0; i<n; ++i) {
        ss.insert(s[i]);
        if (i) {
            int a=(s[i-1]-'a'), b=(s[i]-'a');
            ++mp[a][b];
            if (s[i-1]==s[i])
                ++same;
        }
    }
    for (char c:ss)
        lets.push_back((c-'a'));
    int sz=lets.size();
    for (int i=1; i<(1<<sz); ++i) {
        vector<int> cur;
        for (int j=0; j<sz; ++j)
            if (i&(1<<j))
                cur.push_back(j);
        if (cur.size()==1)
            dp[i]=1;
        else {
            //cout << "we're looking at " << bitset<10>(i) << '\n';
            for (int j:cur) {
                int k=i&(~(1<<j)), add=0;
                //cout << "mask: " << bitset<10>(k) << "\tj: " << j << '\n';
                for (int l=0; l<sz; ++l) {
                    if (k&(1<<l)) {
                        add+=mp[lets[l]][lets[j]];
                        //cout << lets[l] << " " << lets[j] << '\n';
                    }
                }
                dp[i]=min(dp[i], dp[k]+add);
            }
        }
    }
    cout << dp[(1<<sz)-1]+same << '\n';
}

