//I had the right idea but I had to peek at solution for implementation
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("art2.in");
ofstream fout("art2.out");

const int mxN=1e5+1;
int n, beg[mxN], en[mxN], ans;
vector<int> v;

int main() {
    memset(beg, 0x3f, sizeof(beg));
    fin >> n;
    v.pb(0);
    for (int i=0; i<n; ++i) {
        int a; fin >> a;
        v.pb(a);
    }
    v.pb(0);
    n=v.size();
    for (int i=0; i<n; ++i) {
        beg[v[i]]=min(beg[v[i]], i);
        en[v[i]]=max(en[v[i]], i);
    }
    stack<int> st;
    for (int i=0; i<n; ++i) {
        if (i==beg[v[i]]) {
            st.push(v[i]);
            ans=max(ans, int(st.size()));
        }
        if (st.top()!=v[i]) {
            ans=0;
            break;
        }
        if (i==en[v[i]])
            st.pop();
    }
    fout << ans-1 << '\n';
}
