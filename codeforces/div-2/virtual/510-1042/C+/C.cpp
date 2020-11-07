#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+5;
int n, ncnt, mxneg=INT_MIN, npos;
set<int> pos;
vector<int> zpos;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (a<0) {
            ++ncnt;
            if (mxneg<a)
                mxneg=a, npos=i+1;
        }
        if (!a)
            zpos.pb(i+1);
        pos.insert(i+1);
    }
    if (ncnt&1) {
        if (zpos.size())
            cout << "1 " << npos << " " << zpos[0] << '\n';
        else
            cout << "2 " << npos << '\n';
        pos.erase(npos);
    }
    if (zpos.size()) {
        for (int i=1; i<zpos.size(); ++i)
            cout << "1 " << zpos[i-1] << " " << zpos[i] << '\n', pos.erase(zpos[i-1]);
        if (pos.size()>1)
            cout << "2 " << zpos.back() << '\n';
        for (int i:zpos)
            pos.erase(i);
    }
    int lst=-1, cur=-1;
    for (auto it=pos.begin(); it!=pos.end(); ++it) {
        cur=*it;
        if (it!=pos.begin())
            cout << "1 " << lst << " " << cur << '\n';
        lst=cur;
    }
}


