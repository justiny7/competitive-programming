#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//wtf why is this dp so hard - had to look at solution
ifstream fin("odometer.in");
ofstream fout("odometer.out");

const int mxN=50;
ll x, y, dp[mxN][mxN][2][2]; //position, number of digits that are equal to target, are we at current max for this digit?, do we have at least 1 non-zero number?
string s;

ll get(int i, int k, bool atmax, bool good, int t1, int t2=-1) {
    if (i==s.size()) {
        if (!good)
            return 0;
        if (t2>=0) {
            if (k==20)
                return 1;
            return 0;
        }
        if (k>=20)
            return 1;
        return 0;
    }
    if (dp[i][k][atmax][good]>=0)
        return dp[i][k][atmax][good];
    ll ans=0;
    for (int nx=0; nx<10; ++nx) {
        int cmax=s[i]-'0'; //max for current digit
        if (atmax && nx>cmax) //if we're at current max and the next digit is greater than the digit in the original number, then break
            break;
        bool maxq=((nx<cmax)?0:atmax), goodq=(good || nx); //maxq: if next dig<max dig then we're good, otherwise it's whether we're already at the max
        if (goodq && t2>=0)                                //goodq: if we're already good or the next digit isn't a 0, then we're good
            if (nx!=t1 && nx!=t2)
                continue;
        ans+=get(i+1, k+(goodq?((nx==t1)?1:-1):0), maxq, goodq, t1, t2); //k: +0 if we're not good yet, +1 if we add a number that's equal to target, -1 if we don't
    }
    return dp[i][k][atmax][good]=ans; //memoize answers
}

ll solve(ll x) {
    s=to_string(x);
    ll ans=0;
    for (int i=0; i<10; ++i) {
        memset(dp, -1, sizeof(dp));
        ans+=get(0, 20, 1, 0, i);
    }
    for (int i=0; i<10; ++i)
        for (int j=i+1; j<10; ++j) {
            memset(dp, -1, sizeof(dp));
            ans-=get(0, 20, 1, 0, i, j);
        }
    return ans;
}

int main(void) {
    fin >> x >> y, --x;
    fout << solve(y)-solve(x) << '\n';
}
