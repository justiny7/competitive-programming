#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> v(1, 0), b;

int main() {
    int c=0, tot=0;
    while (tot<=1e9) {
        v.pb(v.back()+to_string(++c).size());
        tot+=v.back();
    }
    b=v;
    for (int i=1; i<v.size(); ++i)
        v[i]+=v[i-1];
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--) {
        int x, t, cur=0; cin >> x;
        t=*prev(lower_bound(v.begin(), v.end(), x));
        cur=upper_bound(b.begin(), b.end(), x-t)-b.begin()-1;
        string s=to_string(cur);
        int index=x-t-b[cur]+s.size()-1;
        if (index>=s.size())
            index-=s.size(), ++cur, s=to_string(cur);
        cout << s[index] << '\n';
    }
}

