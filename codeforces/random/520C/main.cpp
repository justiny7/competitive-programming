#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll M=1e9+7;
int n;
string s;
map<char, int> mp;
int a[4];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    for (char c:s)
        ++mp[c];
    int c=0;
    for (auto p:mp)
        a[c++]=p.second;
    sort(a, a+4, greater<int>());
    ll ans=1, p;
    if (a[0]>a[1])
        p=1;
    else if (a[1]>a[2])
        p=2;
    else if (a[2]>a[3])
        p=3;
    else
        p=4;
    for (int i=0; i<n; ++i)
        ans=ans*p%M;
    cout << ans << '\n';
}


