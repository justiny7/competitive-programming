//USACO Silver December 2016 Problem 1
#include <bits/stdc++.h>
using namespace std;
//Ay worked first
ifstream fin("haybales.in");
ofstream fout("haybales.out");

int n, q, h[100001];
map<int, int> bales;

int main(void) {
    fin >> n >> q;
    for (int i=0; i<n; ++i)
        fin >> h[i];
    sort(h, h+n);
    for (int i=0; i<n; ++i)
        bales[h[i]]=i+1;
    if (bales.find(0)==bales.end())
        bales[0]=0;
    for (int i=0; i<q; ++i) {
        int a, b;
        fin >> a >> b;
        auto lo=bales.lower_bound(a), hi=bales.upper_bound(b);
        if (lo!=bales.begin())
            --lo;
        if (hi!=bales.begin())
            --hi;
        if (lo!=bales.end() && hi!=bales.end())
            fout << hi->second-lo->second << '\n';
        else
            fout << "0\n";
    }
}
