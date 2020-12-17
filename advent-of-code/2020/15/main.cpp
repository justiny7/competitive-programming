#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int input[]={0,3,1,6,7,5};
unordered_map<ll, ll> lst;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll cur=0, nxt=input[0];
    for (int i=1; i<=3e7; ++i) { // yay part 2 only took 5 minutes to run!
    //for (int i=1; i<=2020; ++i) { // part 1
        cur=nxt;
        if (i<6)
            nxt=input[i];
        else
            nxt=lst.count(cur)?i-lst[cur]:0;
        lst[cur]=i;
    }
    cout << cur << '\n';
}

