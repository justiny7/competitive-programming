//USACO Silver US Open 2016 Problem 1
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Worked second try because I forgot to do candvec[i/j/k] and did i/j/k directly rip
ifstream fin("reduce.in");
ofstream fout("reduce.out");

const int mxN=50001;
int n, ans=INT_MAX;
pair<pii, int> cows1[mxN], cows2[mxN];
vector<int> candvec;
set<int> cands;

bool sortM(pair<pii, int> a, pair<pii, int> b) {
    if (a.fi.se!=b.fi.se)
        return a.fi.se<b.fi.se;
    return a.fi.fi<b.fi.fi;
}

int area(int a, int b, int c) { //calcs area of cows not including cows a, b, and c
    //cout << a << " " << b << " " << c << '\n';
    int minx, miny, maxx, maxy, i=0;
    while (cows1[i].se==a || cows1[i].se==b || cows1[i].se==c)
        i++;
    minx=cows1[i].fi.fi, i=0;
    while (cows2[i].se==a || cows2[i].se==b || cows2[i].se==c)
        i++;
    miny=cows2[i].fi.se, i=n-1;
    while (cows1[i].se==a || cows1[i].se==b || cows1[i].se==c)
        i--;
    maxx=cows1[i].fi.fi, i=n-1;
    while (cows2[i].se==a || cows2[i].se==b || cows2[i].se==c)
        i--;
    maxy=cows2[i].fi.se;
    return (maxx-minx)*(maxy-miny);
}

int main(void) {
    fin >> n;
    if (n<=3) { //base case
        fout << "0\n";
        return 0;
    }
    for (int i=0; i<n; ++i) {
        fin >> cows1[i].fi.fi >> cows1[i].fi.se;
        cows1[i].se=i;
        cows2[i]=cows1[i];
    }
    sort(cows1, cows1+n);
    sort(cows2, cows2+n, sortM);
    for (int i=0; i<3; ++i) { //gets top 3 right/bottom/left/topmost cows
        cands.insert(cows1[i].se);
        cands.insert(cows1[n-i-1].se);
        cands.insert(cows2[i].se);
        cands.insert(cows2[n-i-1].se);
    }
    for (int i : cands)
        candvec.push_back(i);
    int s=candvec.size();
    for (int i=0; i<s; ++i) //goes through all combinations of candidate cows
        for (int j=i+1; j<s; ++j)
            for (int k=j+1; k<s; ++k)
                ans=min(ans, area(candvec[i], candvec[j], candvec[k]));
    fout << ans << '\n';
}
