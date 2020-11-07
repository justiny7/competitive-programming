//USACO Gold February 2018 Problem

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

//My first attempt at a gold problem
ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

int n, b, d[100001], globmin = INT_MAX;
pii w1, w2, n1, n2; //works1, works2, doesn't work1, doesn't work2 - 1s are based on depth, 2s are based on step

bool comp(pii a, pii b) {
    if (a.se != b.se)
        return (a.se < b.se);
    else
        return (a.fi < b.fi);
}

int main(void) {
    w1 = w2 = n1 = n2 = {-1, -1}; //init pair isn't working
    fin >> n >> b;
    for (int i = 0; i < n; i++)
        fin >> d[i];
    for (int i = 0; i < b; i++) {
        int de, st; //depth, step
        fin >> de >> st;
        if (w1.fi != -1 && ((de >= w1.fi && st >= w1.se) || (de >= w2.fi && st >= w2.se))) {
            fout << "1\n";
            continue;
        }
        if (n1.fi != -1 && ((de <= n1.fi && st <= n1.se) || (de <= n2.fi && st <= n2.se))) {
            fout << "0\n";
            continue;
        }
        int counter = 0;
        bool impos = false;
        for (int j = 0; j < n; j++) {
            if (d[j] > de)
                counter++;
            else
                counter = 0;
            if (counter == st) {
                impos = true;
                break;
            }
        }
        if (impos) {
            fout << "0\n";
            if (de < n1.fi || n1.fi == -1)
                n1 = {de, st};
            else if (de == n1.fi && st < n1.se)
                n1 = {de, st};
            if (st < n2.se || n2.fi == -1)
                n2 = {de, st};
            else if (st == n2.se && de < n2.fi)
                n2 = {de, st};
        }
        else {
            fout << "1\n";
            if (de > w1.fi || w1.fi == -1)
                w1 = {de, st};
            else if (de == w1.fi && st > w1.se)
                w1 = {de, st};
            if (st > w2.se || w2.fi == -1)
                w2 = {de, st};
            else if (st == w2.se && de > w1.fi)
                w2 = {de, st};
        }
    }
    return 0;
}
