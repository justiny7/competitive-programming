//Silver US Open 2019 Problem 2

//Line sweep across x-axis (my computational geometry sucks)
//AYYY worked first try - I honestly can't believe this worked without any major debugging issues (like 2 typos)
//Haha I knew it was too good to be true - I found an exception case and fixed it
#include <bits/stdc++.h>
#define fi first
#define se second
#define x first
#define y second
#define vec vector
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;

ifstream fin("cowjump.in");
ofstream fout("cowjump.out");

int n;
pair<pll, pll> segs[100001]; //Points given segment id
set<pll> all; //All points
map<pll, int> seg; //segment id given point

bool ccw(pll A, pll B, pll C) { //returns if three points are counterclockwise
    return (C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x);
}

bool isect(pair<pll, pll> a, pair<pll, pll> b) { //returns if two line segments intersect
    return (ccw(a.fi, b.fi, b.se) != ccw(a.se, b.fi, b.se) && ccw(a.fi, a.se, b.fi) != ccw(a.fi, a.se, b.se));
}

int main(void) {
    fin >> n;
    for (int i = 1; i <= n; i++) {
        ll a, b, c, d;
        fin >> a >> b >> c >> d;
        if (a < c || (a == c) && b < d)
            segs[i] = {{a, b}, {c, d}};
        else
            segs[i] = {{c, d}, {a, b}};
        all.insert({a, b});
        all.insert({c, d});
        seg[{a, b}] = seg[{c, d}] = i;
    }
    set<pll> curpts;
    set<int> cursegs;
    for (auto it = all.begin(); it != all.end(); it++) {
        if (cursegs.find(seg[*it]) != cursegs.end()) { //If segment is already being processed
            int intnum = 0, lowestint; //check for intersections with all other segments being processed
            for (auto itr = cursegs.begin(); itr != cursegs.end(); itr++)
                if (*itr != seg[*it] && isect(segs[seg[*it]], segs[*itr])) {
                    intnum++;
                    lowestint = *itr;
                }
            if (intnum == 1) {
                intnum = 0;
                //cout << lowestint << '\n';
                for (int i = 1; i <= n; i++)
                    if (i != lowestint && isect(segs[lowestint], segs[i]))
                        intnum++;
                if (intnum == 1)
                    fout << min(lowestint, seg[*it]) << '\n';
                else
                    fout << lowestint << '\n';
                return 0;
            }
            else if (intnum > 1) {
                fout << seg[*it] << '\n';
                return 0;
            }
            curpts.erase(segs[seg[*it]].fi); //then, remove from set
            cursegs.erase(seg[*it]);
        }
        else { //Otherwise, insert into set
            curpts.insert(*it);
            cursegs.insert(seg[*it]);
        }
    }
    return 0;
}
