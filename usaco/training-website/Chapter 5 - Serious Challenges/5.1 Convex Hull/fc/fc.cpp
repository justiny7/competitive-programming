/*
ID: justiny7
LANG: C++
TASK: fc
*/

//Just a convex hull problem
//Update: THIS TOOK ME WAY TOO LONG
#include <bits/stdc++.h>
#define se second
#define fi first
using namespace std;
typedef double db;
typedef pair<db, db> pdd;

ifstream fin("fc.in");
ofstream fout("fc.out");

int n, hull[10001], hp = 2, hs; //hullpos, hullstart
db midx, midy, ans, y[10001], x[10001];
pair<db, int> a[10001];

bool cp(pdd a, pdd b) { //returns if cross product is less than 0 (angle is greater than 180deg)
    db zcp = a.fi*b.se-a.se*b.fi;
    return (zcp < 0);
}

db dist(int p1, int p2) { //returns dist between p1 and p2
    return (db)sqrt((y[p1]-y[p2])*(y[p1]-y[p2])+(x[p1]-x[p2])*(x[p1]-x[p2]));
}

pdd sub(int inda, int indb) { //returns a pair of doubles representing the x- and y- components of the vector resulting from the subtraction of points p1 and p2
    return {x[inda]-x[indb], y[inda]-y[indb]};
}

int main(void) {
    fout << setprecision(2) << fixed;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
        midx += x[i]/n;
        midy += y[i]/n;
    }
    if (n < 2) {
        fout << "0.00\n";
        return 0;
    }
    if (n == 2) {
        fout << dist(0, 1) << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        a[i].first = atan2((y[i]-midy), (x[i]-midx));//*180/(4*atan(1)); //for degrees
        a[i].se = i;
    }
    sort(a, a+n);
    hull[0] = 0;
    hull[1] = 1;
    int i;
    for (i = 2; i < n-1; i++) {
        while (hp > 1 && cp(sub(a[hull[hp-2]].se, a[hull[hp-1]].se), sub(a[hull[hp-1]].se, a[i].se)))
            hp--;
        hull[hp++] = i;
    }
    i = n-1;
    while (hp > 1 && cp(sub(a[hull[hp-2]].se, a[hull[hp-1]].se), sub(a[hull[hp-1]].se, a[i].se)))
        hp--;
    bool f;
    do {
        f = false;
        if (hp-hs > 1 && cp(sub(a[hull[hp-1]].se, a[i].se), sub(a[i].se, a[hull[hs]].se))) {
            i = hull[--hp];
            f = true;
        }
        if (hp-hs > 1 && cp(sub(a[i].se, a[hull[hs]].se), sub(a[hull[hs]].se, a[hull[hs+1]].se))) {
            hs++;
            f = true;
        }
    } while (f);
    hull[hp++] = i;
    for (int j = hs; j < hp; j++) { //FORGOT TO START AT HULLSTART smh
        //cout << hull[j] << " ";
        if (j < hp-1)
            ans += dist(a[hull[j]].se, a[hull[(j+1)%hp]].se);
        else
            ans += dist(a[hull[j]].se, a[hull[hs]].se);
    }
    fout << ans << '\n';
    return 0;
}
