//USACO Silver December 2017 Problem 2
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

//omfg this problem took way too fking long cuz I didn't close an if statement
ifstream fin("measurement.in");
ofstream fout("measurement.out");

int n, g, ans;
pair<int, pair<int, int>> entries[100001];
map<int, int, greater<int>> howmany;
map<int, int> cows;

int main(void) {
    fin >> n >> g;
    for (int i=0; i<n; i++)
        fin >> entries[i].fi >> entries[i].se.fi >> entries[i].se.se;
    sort(entries, entries+n);
    howmany[0]=1e9;
    for (int i=0; i<n; i++) {
        int cow=entries[i].se.fi, dif=entries[i].se.se;
        bool was=(cows[cow]==howmany.begin()->fi), is, del=0;
        howmany[cows[cow]]--;
        if (howmany[cows[cow]]==0) {
            del=1;
            howmany.erase(cows[cow]);
        }
        cows[cow]+=dif;
        howmany[cows[cow]]++;
        is=(cows[cow]==howmany.begin()->fi);
        if (was && (!is || howmany[cows[cow]]>1 || !del))
            ans++;
        else if (is && !was)
            ans++;
    }
    fout << ans << '\n';
}
