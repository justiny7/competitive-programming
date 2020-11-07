#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//Nice, worked first try!
//But still found a flaw...made minor changes
ifstream fin("mooomoo.in");
ofstream fout("mooomoo.out");

const int BIG=0x3f3f3f3f;
int n, b, ans, cows[21], fields[101], dp[100001];
vector<int> moo;

int main(void) {
    fin >> n >> b;
    for (int i=0; i<b; ++i)
        fin >> cows[i];
    for (int i=0; i<n; ++i)
        fin >> fields[i];
    for (int i=n-1; i>0; --i) {
        int c=fields[i]-max(0, fields[i-1]-1);
        if (c<0) {
            fout << "-1\n";
            return 0;
        }
        else if (c>0)
            moo.pb(c);
    }
    if (fields[0]>0)
        moo.pb(fields[0]);
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for (int i=1; i<=100000; ++i) //knapsack for all possible mooing volumes
        for (int j=0; j<b; ++j)
            if (i-cows[j]>=0 && dp[i-cows[j]]<BIG)
                dp[i]=min(dp[i], dp[i-cows[j]]+1);
    for (int i:moo) {
        if (dp[i]<BIG)
            ans+=dp[i];
        else {
            fout << "-1\n";
            return 0;
        }
    }
    fout << ans << '\n';
}
