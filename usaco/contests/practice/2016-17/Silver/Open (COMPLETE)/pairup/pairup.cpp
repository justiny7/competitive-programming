//USACO Silver US Open 2017 Problem 1

//Nice, worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

ifstream fin("pairup.in");
ofstream fout("pairup.out");

int n;
pii cows[100001];

int main() {
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> cows[i].se >> cows[i].fi;
    sort(cows, cows+n);
    int bot = 0, top = n-1, curmax = -1;
    while (bot <= top) {
        if (cows[bot].se == cows[top].se) {
            curmax = max(cows[bot].fi+cows[top].fi, curmax);
            bot++;
            top--;
        }
        if (bot > top)
            break;
        if (bot == top) {
            curmax = max(curmax, 2*cows[top].fi);
            break;
        }
        if (cows[bot].se > cows[top].se) {
            while (cows[bot].se >= cows[top].se && bot < top) {
                curmax = max(cows[bot].fi+cows[top].fi, curmax);
                cows[bot].se -= cows[top].se;
                top--;
            }
            if (bot == top) {
                curmax = max(curmax, 2*cows[top].fi);
                break;
            }
            curmax = max(cows[bot].fi+cows[top].fi, curmax);
        }
        if (cows[top].se > cows[bot].se) {
            while (cows[top].se >= cows[bot].se && bot < top) {
                curmax = max(cows[bot].fi+cows[top].fi, curmax);
                cows[top].se -= cows[bot].se;
                bot++;
            }
            if (bot == top) {
                curmax = max(curmax, 2*cows[top].fi);
                break;
            }
            curmax = max(cows[bot].fi+cows[top].fi, curmax);
        }
    }
    fout << curmax << '\n';
}
