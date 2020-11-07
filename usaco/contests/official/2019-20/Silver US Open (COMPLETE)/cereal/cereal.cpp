//USACO Silver US Open 2020 Problem 2

//Add cows backwards, then process which cows have their cereals taken away
//Omfg I finally got it - this problem was so confusing for me for some reason
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

ifstream fin("cereal.in");
ofstream fout("cereal.out");

int n, m, tot, where[100001], ans[100001];
pii prefs[100001];

void findCow(int cur, int cer) {
    //cout << "cer is at: " << where[cer] << '\n';
    if (where[cer] == 0) { //cereal hasn't been taken yet
        where[cer] = cur;
        tot++;
        return;
    }
    if (where[cer] < cur) //cereal is ahead of current cow in line
        return;
    int now = where[cer];
    where[cer] = cur;
    if (cer == prefs[now].se) //if this cereal is the second preference of the next cow, then we're done
        return;
    findCow(now, prefs[now].se);
}

int main(void) {
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> prefs[i].fi >> prefs[i].se;
    for (int i = n-1; i >= 0; i--) {
        findCow(i, prefs[i].fi);
        ans[i] = tot;
    }
    for (int i = 0; i < n; i++)
        fout << ans[i] << '\n';
    return 0;
}
