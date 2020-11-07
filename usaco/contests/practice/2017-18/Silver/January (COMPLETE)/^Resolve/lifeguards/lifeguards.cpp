//Yay worked first try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, len[mxN];
set<int> t, cows;
map<int, vector<int>> come, go;

int main() {
    ifstream cin("lifeguards.in");
    ofstream cout("lifeguards.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        t.insert(a); t.insert(b);
        come[a].pb(i), go[b].pb(i);
    }
    int cur=0, lst=-1, lst_t, tot=0, lst2=-1;
    for (int p:t) {
        for (int i:come[p])
            cows.insert(i);
        for (int i:go[p])
            cows.erase(i);
        if (~lst)
            len[lst]+=p-lst_t, lst=-1;
        if (cows.size()==1)
            lst=*cows.begin(), lst_t=p;
        if (cows.size() && lst2<0)
            lst2=p;
        else if (cows.empty())
            tot+=p-lst2, lst2=-1;
    }
    sort(len, len+n);
    cout << tot-len[0] << '\n';
}

