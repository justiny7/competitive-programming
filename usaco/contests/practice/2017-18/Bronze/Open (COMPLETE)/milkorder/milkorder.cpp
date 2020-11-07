//USACO Bronze US Open 2018 Problem 2
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

ifstream fin("milkorder.in");
ofstream fout("milkorder.out");

bool mode1;
int n, m, k, hier[101], taken[101];
map<int, int> stuck;

int main(void) {
    fin >> n >> m >> k;
    for (int i=0; i<m; ++i) {
        fin >> hier[i];
        if (hier[i]==1)
            mode1=1;
    }
    for (int i=0; i<k; ++i) {
        int a, b;
        fin >> a >> b;
        if (a==1) {
            fout << b << '\n';
            return 0;
        }
        taken[b]=1;
        stuck[a]=b;
    }
    if (mode1) {
        for (int i=1, j=0; i<=n; ++i) {
            if (!taken[i] && hier[j]==1) {
                fout << i << '\n';
                return 0;
            }
            if (!taken[i] && stuck.find(hier[j])==stuck.end())
                stuck[hier[j]]=1, taken[i]=1, ++j;
            else if (stuck.find(hier[j])!=stuck.end())
                i=stuck[hier[j]], ++j;
        }
    }
    int i=n, j=m-1;
    for (; i>0, j>=0; --i) {
        if (!taken[i] && stuck.find(hier[j])==stuck.end()) {
            stuck[hier[j]]=i;
            taken[i]=1;
            --j;
        }
        else if (stuck.find(hier[j])!=stuck.end()) {
            i=stuck[hier[j]];
            --j;
        }
    }
    //for (int i=1; i<=n; ++i)
        //cout << "cow " << i << " is stuck at " << stuck[i] << '\n';
    //cout << '\n';
    if (stuck.find(1)!=stuck.end()) {
        fout << stuck[1] << '\n';
        return 0;
    }
    for (int i=1; i<=n; ++i)
        if (!taken[i]) {
            fout << i << '\n';
            return 0;
        }
}
