//USACO Silver February 2018 Problem 1

//Strat - calculate maximum immediate profit ((dist*rf)-(dist*rb))*value, go there, then recalc next best immediate profit for the stops ahead
//New strat - find first increasing subsequence from the end, and go to all values on that sequence for the max possible time
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ifstream fin("reststops.in");
ofstream fout("reststops.out");

int l, n, rf, rb;
pii rs[100001]; //rest stops
vector<int> biggests;

int main(void) {
    fin >> l >> n >> rf >> rb;
    for (ll i = 0; i < n; i++)
        fin >> rs[i].fi >> rs[i].se;
    if (n == 1) {
        fout << rs[0].se*(rf-rb)*rs[0].fi << '\n';
        return 0;
    }
    sort(rs, rs+n);
    int last = 0;
    for (ll i = n-1; i >= 0; i--)
        if (rs[i].se > last) {
            biggests.pb(i);
            last = rs[i].se;
        }
    reverse(biggests.begin(), biggests.end());
    ll curpos = 0, fjt = 0, besst = 0, ans = 0; //FJ time, Bessie time
    for (int i = 0; i < biggests.size(); i++) {
        fjt += (rs[biggests[i]].fi-curpos)*rf;
        besst += (rs[biggests[i]].fi-curpos)*rb;
        ans += rs[biggests[i]].se*(fjt-besst);
        curpos = rs[biggests[i]].fi;
        besst = fjt; //farmer john catches up
    }
    fout << ans << '\n';
    return 0;
}

/* Old
    ll cur = 0, curpos = 0;
    while (cur < n) {
        ll maxprof = -1, maxind;
        for (ll i = cur; i < n; i++) if ((rs[i].fi-curpos)*(rf-rb)*rs[i].se > maxprof) {
                maxprof = rs[i].se*(rf-rb)*(rs[i].fi-curpos);
                //cout << maxprof << '\n';
                maxind = i;
            }
        ans += maxprof;
        cur = maxind+1;
        curpos = rs[maxind].fi;
    }*/

