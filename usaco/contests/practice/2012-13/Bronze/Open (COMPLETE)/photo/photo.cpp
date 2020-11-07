//Coordinate compression renders n useless xd
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int mxN=2e3+1;
int n, k;
pair<int, int> p[mxN];
map<int, int> mp;
set<int> t, s[mxN], cur;

int main() {
    ifstream cin("photo.in");
    ofstream cout("photo.out");
    cin >> n >> k;
    for (int i=0; i<k; ++i) {
        cin >> p[i].fi >> p[i].se;
        t.insert(p[i].fi);
        t.insert(p[i].se);
    }
    int c=0;
    for (int i:t)
        mp[i]=c++;
    for (int i=0; i<k; ++i) {
        int a=mp[p[i].fi], b=mp[p[i].se];
        s[a].insert(b);
        s[b].insert(a);
    }
    int ans=1;
    for (int i=0; i<c; ++i) {
        for (int j:s[i])
            if (cur.count(j)) {
                ++ans;
                cur.clear();
                break;
            }
        cur.insert(i);
    }
    cout << ans << '\n';
}

