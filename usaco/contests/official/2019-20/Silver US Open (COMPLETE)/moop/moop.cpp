//USACO Silver US Open 2020 Problem 3

//Pretty interesting problem but it took me too long
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

ifstream fin("moop.in");
ofstream fout("moop.out");

int n, groupnum = 1;
vector<int> lbs; //lower bounds
pii particles[100001];

bool sortmeth(pii a, pii b) {
    if (a.fi != b.fi)
        return (a.fi < b.fi);
    return (a.se > b.se);
}

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> particles[i].fi >> particles[i].se;
    sort(particles, particles+n, sortmeth);
    int maxh = INT_MAX, minh;
    lbs.pb(INT_MAX);
    for (int i = 0; i < n; i++) {
        //cout << groupnum << " " << minh << " " << maxh << '\n';
        //cout << particles[i].fi << " " << particles[i].se << '\n';
        if (i == 0) {
            minh = particles[i].se;
            continue;
        }
        if ((particles[i].se < maxh) && (particles[i].se >= minh || (particles[i].fi == particles[i-1].fi)))
            minh = min(particles[i].se, minh);
        else if (particles[i].se >= maxh) {
            int sz = lbs.size()-1, k = sz;
            while (particles[i].se >= lbs[k] && k >= 0) {
                lbs.pop_back();
                k--;
            }
            groupnum -= (sz-k);
            //assert(groupnum > 0);
            maxh = lbs[k];
        }
        else if (particles[i].se < minh) {
            groupnum++;
            lbs.pb(minh);
            maxh = minh;
            minh = particles[i].se;
        }
    }
    fout << groupnum << '\n';
    return 0;
}
