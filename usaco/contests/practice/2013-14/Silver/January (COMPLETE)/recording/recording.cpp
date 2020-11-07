#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Yay worked first try
ifstream fin("recording.in");
ofstream fout("recording.out");

const int mxN=151;
int n, ans, next1, next2;
pii p[mxN];

bool cmp(pii a, pii b) {
    if (a.se!=b.se)
        return a.se<b.se;
    return a.fi<b.fi;
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> p[i].fi >> p[i].se;
    sort(p, p+n, cmp);
    for (int i=0; i<n; ++i) {
        if (p[i].fi>=next1 && p[i].fi>=next2)
            ++ans, (next1>next2)?next1=p[i].se:next2=p[i].se;
        else if (p[i].fi>=next1)
            ++ans, next1=p[i].se;
        else if (p[i].fi>=next2)
            ++ans, next2=p[i].se;
    }
    fout << ans << '\n';
}
