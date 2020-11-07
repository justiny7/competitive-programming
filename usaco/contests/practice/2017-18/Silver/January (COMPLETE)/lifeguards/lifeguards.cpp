//USACO Silver January 2018 Problem 1

/*
 * Idea - keep track of intervals of 1s, and see if each interval maps to 1 single lifeguard. If yes, do (time covered by all lifeguards) - (min interval of 1s)
 * Otherwise, if more than 1 interval of ones is covered by 1 lifeguard, it's guaranteed to entirely cover the shift of another lifeguard, so if you fire the
 * covered lifeguard you achieve the maximum time covered - the time covered by all lifeguards
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int n, lastbreak, alltime, minBreak = INT_MAX;
pii lgs[100001]; //lifeguards
map<int, int> times;
vector<pii> ones;

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        lgs[i] = {a, b};
        times[a]++;
        times[b]--;
    }
    sort(lgs, lgs+n);
    int numcows = 0;
    bool lastone = false;
    for (pii p : times) {
        if (numcows == 0)
            lastbreak = p.fi;
        if (lastone) {
            ones[ones.size()-1].se = p.fi;
            lastone = false;
        }
        numcows += p.se;
        if (numcows == 0)
            alltime += p.fi-lastbreak;
        if (numcows == 1) {
            ones.pb({p.fi, -1});
            lastone = true;
        }
    }
    int oneind = 0;
    for (int i = 0; i < n; i++)  {
        //cout << oneind << '\n';
        int lastind = oneind;
        while (oneind < ones.size() && (ones[oneind].fi >= lgs[i].fi && ones[oneind].se <= lgs[i].se))
            oneind++;
        if (oneind-lastind != 1 || (oneind == ones.size() && i != n-1)) {
            fout << alltime << '\n';
            return 0;
        }
        else
            minBreak = min(minBreak, ones[oneind-1].se-ones[oneind-1].fi);
        //cout << ones[oneind-1].fi << " " << ones[oneind-1].se << '\n';
        //cout << "minbreak: " << minBreak << '\n';
    }
    fout << alltime-minBreak << '\n';
    return 0;
}
