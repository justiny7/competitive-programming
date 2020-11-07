#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//Finally got it after toying with pretty much all other possible combinations of greedy solutions
ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

const int mxN=5e4+1;
int n, ans;
vector<int> bessie, e1, e2;
bool taken[mxN*2];

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        int a; fin >> a;
        taken[a]=1;
        if (i*2<n)
            e1.pb(a);
        else
            e2.pb(a);
    }
    for (int i=1; i<=2*n; ++i)
        if (!taken[i])
            bessie.push_back(i);
    sort(bessie.begin(), bessie.end());
    sort(e1.begin(), e1.end()); sort(e2.begin(), e2.end());
    int cur=n/2-1;
    for (int i=n/2-1; i>=0; --i)
        if (bessie[i]<e2[cur])
            --cur;
    ans+=n/2-1-cur, cur=0;
    for (int i=n/2; i<n; ++i)
        if (bessie[i]>e1[cur])
            ++cur;
    ans+=cur;
    fout << ans << '\n';
}
