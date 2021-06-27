#include <bits/stdc++.h>
using namespace std;

// At most 2 primes factors
// Divide out squares --> either 1, prime, or prime * another prime
// Graph of 1 and primes, for each element connect corresponding nodes
//  --> find shortest cycle

const int N = 1e5 + 69, V = 1e6 + 69;
int n, spf[V], dist[V], par[V];
array<int, 2> a[N];
vector<int> adj[V], primes;
map<pair<int, int>, int> mp;

void sieve() {
    for (int i = 1; i < V; ++i)
        spf[i] = (i & 1) ? i : 2;

    primes = {1, 2};
    for (long long i = 3; i < V; ++i) {
        if (spf[i] == i) {
            primes.push_back(i);
            for (long long j = i * i; j < V; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int go(int st) {
    for (int i : primes)
        dist[i] = -1, par[i] = -1;

    int ret = INT_MAX;

    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while (q.size()) {
        int v = q.front(); q.pop();

        for (int u : adj[v]) {
            if (dist[u] < 0) {
                dist[u] = dist[v] + 1;
                par[u] = v;
                q.push(u);
            }
            else if (par[u] != v && par[v] != u) {
                //if (st == 1)
                //cout << "> " << u << " " << v << '\n';
                ret = min(ret, dist[v] + dist[u] + 1);
            }
        }
    }

    //cout << st << " " << ret << '\n';

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    sieve();

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, j = 1; cin >> x;

        a[i] = {1, 1};
        while (x > 1) {
            int d = spf[x], c = 0;
            while (x % d == 0)
                x /= d, ++c;

            if (c & 1)
                a[i][j--] = d;
        }

        //cout << a[i][0] << " " << a[i][1] << '\n';

        if (a[i][0] == 1 && a[i][1] == 1) {
            cout << "1\n";
            return 0;
        }

        ++mp[make_pair(min(a[i][0], a[i][1]), max(a[i][0], a[i][1]))];
    }

    for (auto [x, c] : mp) {
        if (c > 1) {
            cout << "2\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        adj[a[i][0]].push_back(a[i][1]);
        adj[a[i][1]].push_back(a[i][0]);
    }

    int ans = INT_MAX;
    for (int i = 1; i * i < V; ++i)
        if (spf[i] == i)
            ans = min(ans, go(i));

    cout << (ans < INT_MAX ? ans : -1) << '\n';
}
