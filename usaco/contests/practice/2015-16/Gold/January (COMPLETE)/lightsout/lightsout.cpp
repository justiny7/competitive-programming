#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Turns out it was just a problem with notepad encryption
//Welp turned out I kept getting testcase 8 wrong because I misread the question
//I didn't realize that she can feel angles separately from lengths
ifstream fin("lightsout.in");
ofstream fout("lightsout.out");

const int mxN=201;
int n, m, mindist[mxN], totdist, ans;
vector<int> path;
pii a[mxN];
map<vector<int>, int> mp;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i].fi >> a[i].se;
    for (int i=0; i<n; ++i) {
        int j=(i+1)%n, k=(i-1+n)%n;
        if ((a[k].fi-a[i].fi)*(a[j].se-a[i].se)-(a[j].fi-a[i].fi)*(a[k].se-a[i].se)>0) //switch to cross product
            m=1;
        else
            m=-1;
        path.pb(m);
        path.pb(abs(a[j].fi-a[i].fi+a[j].se-a[i].se));
        totdist+=path.back();
    }
    path.pb(0);
    for (int i=0; i<path.size(); i+=2) { //counting frequency of all paths
        vector<int> cur;
        for (int j=i; j<path.size(); ++j) {
            cur.pb(path[j]);
            if (!(j&1))
                ++mp[cur];
        }
    }
    for (int i=0, cur=0; i<n; ++i) {
        cur+=path[i*2+1];
        mindist[i+1]=min(cur, totdist-cur);
    }
    for (int i=1; i<n; ++i) { //goes through each vertex and advances the j point until path is unique or until exit is reached
        int j=i*2, curlen=0;
        vector<int> cur;
        for (; j<path.size(); ++j) {
            cur.pb(path[j]);
            if (!(j&1)) {
                if (mp[cur]==1)
                    break;
                curlen+=path[j+1];
            }
        }
        ans=max(ans, curlen+mindist[j/2]-mindist[i]); //ckmax the answer
    }
    fout << ans << '\n';
}
