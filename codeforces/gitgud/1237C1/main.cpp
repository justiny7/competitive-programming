#include <bits/stdc++.h>
using namespace std;

const int mxN=2e3+1;
int n;
struct point {
    int x, y, z, ind;
} a[mxN];
bool taken[mxN];

inline int dist(int i, int j) {
    return (abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].x >> a[i].y >> a[i].z, a[i].ind=i+1;
    for (int t=0; t<n/2; ++t) {
        int i=0, mn=INT_MAX, c;
        for (; taken[i]; ++i);
        taken[i]=1;
        for (int j=0; j<n; ++j)
            if (!taken[j] && dist(i, j)<mn)
                c=j, mn=dist(i, j);
        cout << a[i].ind << " " << a[c].ind << '\n';
        taken[c]=1;
    }
}

