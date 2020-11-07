//USACO Silver January 2016 Problem 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("div7.in");
ofstream fout("div7.out");

int n, cows[50001], prefs[50001];
map<int, pair<int, int>> inds;

int main(void) {
    fin >> n;
    for (int i=0; i<n; i++) {
        fin >> cows[i];
        cows[i]%=7; //avoid overflow
        if (i==0)
            prefs[i]=cows[i];
        else
            prefs[i]=cows[i]+prefs[i-1];
        prefs[i]%=7;
    }
    for (int i=0; i<7; i++)
        inds[i]={INT_MAX, INT_MIN};
    int maxdif=-1;
    for (int i=0; i<n; i++) { //look for longest dif of eq prefsums
        inds[prefs[i]].first = min(inds[prefs[i]].first, i);
        inds[prefs[i]].second = max(inds[prefs[i]].second, i);
    }
    for (auto p : inds)
        maxdif = max(maxdif, p.second.second-p.second.first);
    fout << maxdif << '\n';
}
