#include <bits/stdc++.h>
using namespace std;

const int mxN=3e5+1;
int n, cnt[3], need[3];
string s, ans;
bool vis[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s, ans=s;
    for (int i=0; i<n; ++i)
        ++cnt[s[i]-'0'];
    for (int i=0; i<3; ++i)
        need[i]=n/3-cnt[i];
    for (int i=0; need[0]>0; ++i)
        if (s[i]!='0' && need[s[i]-'0']<0)
            ans[i]='0', --need[0], ++need[s[i]-'0'], vis[i]=1;
    for (int i=n-1; i>=0 && need[2]>0; --i)
        if (s[i]!='2' && need[s[i]-'0']<0)
            ans[i]='2', --need[2], ++need[s[i]-'0'], vis[i]=1;
    for (int i=n-1; i>=0 && need[1]>0; --i)
        if (!vis[i] && s[i]=='0' && need[0]<0)
            ans[i]='1', --need[1], ++need[0], vis[i]=1;
    for (int i=0; i<n && need[1]>0; ++i)
        if (!vis[i] && s[i]=='2' && need[2]<0)
            ans[i]='1', --need[1], ++need[0], vis[i]=1;
    cout << ans << '\n';
}
