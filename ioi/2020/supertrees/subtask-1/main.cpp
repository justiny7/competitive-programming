#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;

int n;

int construct(vvi p) {
    n=p.size();
    vvi ans(n, vi(n));
    for (int i=0; i<n; ++i) {
        if (i)
            ans[i-1][i]=ans[i][i-1]=1;
        if (i<n-1)
            ans[i+1][i]=ans[i][i+1]=1;
    }
    build(ans);
    return 1;
}

