#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ld=long double;
using ll=long long;
//Kinda confusing but I worked it out
//Surprised long double accuracy was good enough lol
ifstream fin("slowdown.in");
ofstream fout("slowdown.out");

int n;
vector<ll> d, t;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        char c; ll a;
        fin >> c >> a;
        if (c=='T')
            t.pb(a);
        else
            d.pb(a);
    }
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());
    if (d.back()!=1000)
        d.pb(1000);
    int i=0, j=0, n=d.size(), m=t.size();
    ld dist=0, time=0, speed=1;
    while (i<n || j<m) {
        ld next_t=(d[i]-dist)*speed;
        //cout << "time to get to next dist checkpoint: " << next_t << '\n';
        while (j<m && time+next_t>=t[j]) {
            dist+=(t[j]-time)/speed, ++speed;
            time=t[j], next_t=(d[i]-dist)*speed, ++j;
            //cout << "new dist:" << dist << '\n';
            //cout << "new time:" << time << '\n';
        }
        time+=(d[i]-dist)*speed, dist=d[i], ++speed, ++i;
        //cout << "dist: " << dist << "\ttime: " << time << '\n';
    }
    fout << ll(round(time)) << '\n';
}
