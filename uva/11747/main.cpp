#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1;
int n, m, par[mxN], sz[mxN];
struct edge {
    int a, b, w;
    bool operator<(const edge& e) {
        return w<e.w;
    }
};
vector<edge> v;
vector<int> ans;

int find(int v) {
    return (v==par[v]?v:par[v]=find(par[v]));
}
bool merge(int a, int b) {
    a=find(a), b=find(b);
    if (a^b) {
        if (sz[b]>sz[a])
            swap(a, b);
        par[b]=a, sz[a]+=sz[b];
        return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    while (n || m) {
        ans.clear();
        v=vector<edge>(m);
        for (int i=0; i<n; ++i)
            sz[i]=1, par[i]=i;
        for (int i=0; i<m; ++i) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            v[i]=edge{a, b, c};
        }
        sort(v.begin(), v.end());
        for (int i=0; i<m; ++i)
            if (!merge(v[i].a, v[i].b))
                ans.push_back(v[i].w);
        if (ans.size()) {
            sort(ans.begin(), ans.end());
            for (int i=0; i<ans.size()-1; ++i)
                printf("%d ", ans[i]);
            printf("%d\n", ans.back());
        }
        else
            printf("forest\n");
        scanf("%d %d", &n, &m);
    }
}

