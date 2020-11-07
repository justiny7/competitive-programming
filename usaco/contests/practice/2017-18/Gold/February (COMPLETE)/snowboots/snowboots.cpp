//USACO Gold February 2018 Problem 1
//Attempt 2: sort boots by descending order, then delete tiles greater and count maxdist between tiles - if maxdist > step, then it won't work
//You can delete tiles b/c smaller boots are guaranteed to not use bigger tiles

#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define sz size()
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

int n, b, ne[100001], pr[100001]; //keep track of connected tiles
vec<pii> tiles;
vec<pair<pii, int>> boots;
bool ans[100001];

int main(void) {
    fin >> n >> b;
    for (int i = 0; i < n; i++) {
        ne[i] = i+1;
        pr[i] = i-1;
        int a;
        fin >> a;
        tiles.pb({a, i});
    }
    sort(tiles.begin(), tiles.end());
    //for (auto i : tiles)
    //    cout << i.fi << " " << i.se <<'\n';
    for (int i = 0; i < b; i++) {
        int de, st;
        fin >> de >> st;
        boots.pb({{de, st}, i});
    }
    sort(boots.begin(), boots.end());
    //for (auto i : boots)
    //    cout << i.fi.fi << " " << i.fi.se << " " << i.se <<'\n';
    int ct = n-1, cm = 1; //curtile, curmax
    for (int i = b-1; i >= 0; i--) {
        //cout << "nxt:" << ne[0] << '\n';
        //cout << "cur: " << ct << '\n';
        while (ct >= 0 && tiles[ct].fi > boots[i].fi.fi) {
            ne[pr[tiles[ct].se]] = ne[tiles[ct].se]; //elims tile from chain
            pr[ne[tiles[ct].se]] = pr[tiles[ct].se];
            cm = max(cm, ne[tiles[ct].se]-pr[tiles[ct].se]);
            ct--;
        }
        ans[boots[i].se] = (cm <= boots[i].fi.se);
        //cout << boots[i].se << " " << cm << '\n';
    }
    for (int i = 0; i < b; i++)
        fout << ans[i] << '\n';
    return 0;
}
