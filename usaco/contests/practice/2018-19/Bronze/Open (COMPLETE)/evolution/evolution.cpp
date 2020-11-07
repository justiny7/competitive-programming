//USACO Bronze US Open 2019 Problem 3

#include <bits/stdc++.h>
#define pb push_back
#define ve vector
using namespace std;

ifstream fin("evolution.in");
ofstream fout("evolution.out");

int n;
ve<string> traits[26], all;
unordered_set<string> t;

bool common(int a, int b) { //returns whether trait a and trait b share at least 1 group and don't share at least 1 group - if yes, then it's impos
    bool aa = false, bb = false, both = false;
    for (int i = 0; i < n; i++) {
        bool ca = false, cb = false;
        for (int j = 0; j < traits[i].size(); j++) {
            if (traits[i][j] == all[a])
                ca = true;
            else if (traits[i][j] == all[b])
                cb = true;
        }
        if (ca && cb)
            both = true;
        else if (ca)
            aa = true;
        else if (cb)
            bb = true;
    }
    return (aa && bb && both);
}

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        fin >> a;
        for (int j = 0; j < a; j++) {
            string s;
            fin >> s;
            traits[i].pb(s);
            t.insert(s);
        }
    }
    for (auto it = t.begin(); it != t.end(); it++)
        all.pb(*it);
    for (int i = 0; i < all.size(); i++)
        for (int j = i+1; j < all.size(); j++)
            if (common(i, j)) {
                fout << "no\n";
                return 0;
            }
    fout << "yes\n";
    return 0;
}
