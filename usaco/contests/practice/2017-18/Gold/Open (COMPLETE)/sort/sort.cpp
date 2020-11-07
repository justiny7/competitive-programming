//Looked at solution for hint
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, a[mxN], b[mxN], bit[mxN], ans;

bool cmp(int x, int y) {
    return a[x]<a[y];
}

void upd(int i) {
    for (++i; i<=n; i+=i&(-i))
        ++bit[i];
}

int query(int i) {
    int sum=0;
    for (++i; i; i-=i&(-i))
        sum+=bit[i];
    return sum;
}

int main() {
    ifstream cin("sort.in");
    ofstream cout("sort.out");
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i], b[i]=i;
    sort(b, b+n, cmp);
    for (int i=0; i<n-1; ++i) {
        upd(b[i]);
        ans=max(ans, i+1-query(i));
    }
    cout << (ans?ans:1) << '\n';
}

