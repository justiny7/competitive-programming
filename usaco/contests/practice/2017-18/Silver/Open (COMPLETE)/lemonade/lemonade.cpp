//USACO Silver US Open 2018 Problem 2

#include <bits/stdc++.h>
using namespace std;

ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

int n, cows[100001];

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++)
        fin >> cows[i];
    sort(cows, cows+n);
    int linecnt = 0;
    for (int i = n-1; i >= 0; i--) {
        if (cows[i] >= linecnt)
            linecnt++;
        else
            break;
    }
    fout << linecnt << '\n';
    return 0;
}
