//USACO Silver February 2016 Problem 2
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
//Welp I guess directly calculating it doesn't work - brute force time
//mxN=1e3 means O(N^2) will work
//yay it worked
ifstream fin("balancing.in");
ofstream fout("balancing.out");

int n, ans=INT_MAX;
pair<int, int> pts[1001];
map<int, int> x, y;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        int a, b;
        fin >> a >> b;
        x[a]++;
        y[b]++;
        pts[i]={a, b};
    }
    sort(pts, pts+n);
    int cury, ycnt=0;
    for (auto& p : y) {//go through all y's, sweep x's
        cury=p.fi+1;
        ycnt+=p.se;
        int m1, m2, m3, m4;
        m1=m3=0, m2=ycnt, m4=n-ycnt;
        //cout << cury << '\n';
        for (int i=0; i<n; ++i) {
            if (pts[i].se>cury)
                m3++, m4--;
            else
                m1++, m2--;
            //cout << m1 << " " << m3 << " " << m2 << " " << m4 << '\n';
            ans=min(ans, max({m1, m2, m3, m4}));
        }
        //cout << '\n';
    }
    fout << ans << '\n';
}
