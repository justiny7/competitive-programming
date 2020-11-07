//Yay got it after some debugging
#include <bits/stdc++.h>
#define se second
#define lb lower_bound
using namespace std;
using pii=pair<int, int>;
using pie=pair<pii, int>;

const int mxN=1e5+1;
int n, d, bes[mxN*2], els[mxN*2], ans[mxN*2];
multiset<pii, greater<pii>> bessie, elsie;
queue<int> q;

int main() {
    memset(ans, -1, sizeof(ans));
    ifstream cin("piepie.in");
    ofstream cout("piepie.out");
    cin >> n >> d;
    for (int i=0; i<n*2; ++i)
        cin >> bes[i] >> els[i];
    for (int i=0; i<n; ++i) {
        if (!bes[i+n])
            q.push(i+n), ans[i+n]=1;
        else
            elsie.insert(pii(bes[i+n], i+n));
        if (!els[i])
            q.push(i), ans[i]=1;
        else
            bessie.insert(pii(els[i], i));
    }
    while (!q.empty()) {
        int ind=q.front(); q.pop();
        if (ind<n)
            while (!elsie.empty()) {
                auto it=elsie.lb(pii(bes[ind], INT_MAX));
                if (it==elsie.end() || bes[ind]-bes[it->se]>d)
                    break;
                ans[it->se]=ans[ind]+1;
                q.push(it->se);
                elsie.erase(it);
            }
        else
            while (!bessie.empty()) {
                auto it=bessie.lb(pii(els[ind], INT_MAX));
                if (it==bessie.end() || els[ind]-els[it->se]>d)
                    break;
                ans[it->se]=ans[ind]+1;
                q.push(it->se);
                bessie.erase(it);
            }
    }
    for (int i=0; i<n; ++i)
        cout << ans[i] << '\n';
}

