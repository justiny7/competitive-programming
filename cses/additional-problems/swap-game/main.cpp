#include <bits/stdc++.h>
using namespace std;

const int op1[]={0,1,0,1,2,3,4,3,4,5,6,7}, op2[]={1,2,3,4,5,4,5,6,7,8,7,8};
unordered_map<string, int> vis, vis2;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i=0; i<9; ++i) {
        char c; cin >> c;
        s.push_back(c);
    }
    queue<string> q;
    q.push(s);
    while (q.size()) {
        string cur=q.front(); q.pop();
        if (cur=="123456789") {
            cout << vis[cur] << '\n';
            return 0;
        }
        if (vis[cur]>8)
            continue;
        for (int i=0; i<12; ++i) {
            string nxt=cur;
            swap(nxt[op1[i]], nxt[op2[i]]);
            if (!vis[nxt])
                vis[nxt]=vis[cur]+1, q.push(nxt);
        }
    }
    q.push("123456789");
    while (q.size()) {
        string cur=q.front(); q.pop();
        if (vis[cur]) {
            cout << vis[cur]+vis2[cur] << '\n';
            return 0;
        }
        if (vis2[cur]>8)
            continue;
        for (int i=0; i<12; ++i) {
            string nxt=cur;
            swap(nxt[op1[i]], nxt[op2[i]]);
            if (!vis2[nxt])
                vis2[nxt]=vis2[cur]+1, q.push(nxt);
        }
    }
}

