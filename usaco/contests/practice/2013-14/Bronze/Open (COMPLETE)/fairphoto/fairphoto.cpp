//Yay got it second try after I realized I skimmed over a kinda important part of the problem statement
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, pref, ans;
map<int, int> mp;
pii a[mxN];

int main() {
    ifstream cin("fairphoto.in");
    ofstream cout("fairphoto.out");
    cin >> n;
    for (int i=1; i<=n; ++i) {
        char c;
        cin >> a[i].fi >> c;
        a[i].se=(c=='G')?1:-1;
    }
    sort(a+1, a+n+1);
    for (int i=1, cur=1; i<=n; ++i) {
        if (a[i].se==a[cur].se)
            ans=max(ans, a[i].fi-a[cur].fi);
        else
            cur=i;
    }
    mp[0]=0;
    for (int i=1; i<=n; ++i) {
        pref+=a[i].se;
        if (mp.count(pref))
            ans=max(ans, a[i].fi-a[mp[pref]+1].fi);
        else
            mp[pref]=i;
    }
    cout << ans << '\n';
}

