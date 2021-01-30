#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, k, ans, a[mxN];
map<int, int> mp;
multiset<int> s;

int main() {
    ifstream cin("lineup.in");
    ofstream cout("lineup.out");
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int l=0, r=0; l<n; ++l) {
        while (r<n) {
            int cur=a[r];
            if (mp.size()==k+1 && !mp.count(cur))
                break;
            if (mp.count(cur))
                s.erase(s.find(mp[cur]));
            s.insert(++mp[cur]);
            ++r;
        }
        ans=max(ans, *s.rbegin());
        s.erase(s.find(mp[a[l]]));
        if (--mp[a[l]])
            s.insert(mp[a[l]]);
        else
            mp.erase(a[l]);
    }
    cout << ans << '\n';
}

