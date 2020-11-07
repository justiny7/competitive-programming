//USACO Silver December 2016 Problem 2
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
//Also pretty easy - I forgot the a==b thing so 3rd try :c
ifstream fin("citystate.in");
ofstream fout("citystate.out");

int n, ans;
map<pair<string, string>, int> cities;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        string a, b;
        fin >> a >> b;
        cities[{a.substr(0, 2), b}]++;
    }
    for (auto& p : cities) {
        string a=p.fi.fi, b=p.fi.se;
        if (a==b)
            continue;
        if (cities.find({b, a})!=cities.end())
            ans+=p.se*cities[{b, a}];
    }
    fout << ans/2 << '\n';
}
