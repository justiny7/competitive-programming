//Yay worked first try
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
ll st, en;
string s, ss;
set<ll> ans;

ll to_ll(string x) {
    ll ret=0;
    for (int i=0; i<x.size(); ++i)
        ret=ret*10+(x[i]-'0');
    return ret;
}

//a=switched already, b=no leading 0s, c=have at least 1 rep, d=can take 0-9
void go(int ind=-1, int rep=-1, bool a=0, bool b=0, bool c=0, bool d=0) {
    if (ind==n) {
        if (a && b && c)
            ans.insert(to_ll(ss));
        return;
    }
    if (ind<0)
        for (int i=0; i<10; ++i)
            go(0, i);
    else {
        int cur=s[ind]-'0';
        for (int i=0; i<=(d?9:cur); ++i) {
            bool b2=(b || i>0), c2=((c || i==rep) && b2), d2=(d || i<cur);
            if (!a && b2 && (i^rep)) {
                ss+=to_string(i);
                go(ind+1, rep, 1, b2, c2, d2);
                ss.pop_back();
            }
            else if (!b2 || (i==rep)) {
                ss+=to_string(i);
                go(ind+1, rep, a, b2, c2, d2);
                ss.pop_back();
            }
        }
    }
}

int solve(ll x) {
    ans.clear();
    s=to_string(x), n=s.size();
    go();
    return ans.size();
}

int main() {
    ifstream cin("odometer.in");
    ofstream cout("odometer.out");
    cin >> st >> en;
    cout << solve(en)-solve(st-1) << '\n';
}

