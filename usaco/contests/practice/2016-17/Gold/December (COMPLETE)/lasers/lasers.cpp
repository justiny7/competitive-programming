#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;
//TLE'd at first with stupid bfs so I looked at solution for hint
//Ahh finally got it after creating custom hash and trying to interpret Java code smh
ifstream fin("lasers.in");
ofstream fout("lasers.out");

struct line {
    int v;
    bool hor;
    line(int v, bool hor):v(v), hor(hor) {}

    int hash() {
        return (2*v+hor)*71;
    }

    bool operator<(line a) const {
        return (2*v+hor)*71<a.hash();
    }
};

const int mxN=1e5+1;
int n, xl, yl, xb, yb;
pii a[mxN];
map<int, int> mp;
map<int, vector<int>> xs, ys;

int main() {
    fin >> n >> xl >> yl >> xb >> yb;
    mp[line(yl, 1).hash()]=0;
    mp[line(xl, 0).hash()]=0;
    for (int i=0; i<n; ++i) {
        int x, y;
        fin >> x >> y;
        xs[x].pb(y);
        ys[y].pb(x);
    }
    queue<line> q;
    q.push(line(yl, 1));
    q.push(line(xl, 0));
    while (!q.empty()) {
        line cur=q.front(); q.pop();
        if (cur.hor && cur.v==yb ||
            !cur.hor && cur.v==xb) {
            fout << mp[cur.hash()] << '\n';
            return 0;
        }
        for (int i:(cur.hor?ys:xs)[cur.v]) {
            line nxt(i, !cur.hor);
            if (!mp.count(nxt.hash())) {
                mp[nxt.hash()]=mp[cur.hash()]+1;
                q.push(nxt);
            }
        }
    }
    fout << "-1\n";
}
