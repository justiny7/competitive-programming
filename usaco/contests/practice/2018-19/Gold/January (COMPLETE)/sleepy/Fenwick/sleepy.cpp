#include <bits/stdc++.h>
using namespace std;

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

const int mxN=1e5+1;
int n, a[mxN], bit[mxN];
vector<int> ans;

void upd(int i) {
    for (; i<=n; i+=i&(-i))
        ++bit[i];
}

int query(int i) {
    int ans=0;
    for (; i; i-=i&(-i))
        ans+=bit[i];
    return ans;
}

int main() {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    int j=n-2;
    upd(a[n-1]);
    for (; j>=0; --j) {
        if (a[j]>a[j+1])
            break;
        upd(a[j]);
    }
    for (int i=0, add=j; i<=j; ++i, --add) {
        int nxt=query(a[i]);
        ans.push_back(nxt+add);
        upd(a[i]);
    }
    fout << ans.size() << '\n';
    for (int i=0; i<ans.size(); ++i) {
        if (i)
            fout << " ";
        fout << ans[i];
    }
    fout << '\n';
}

