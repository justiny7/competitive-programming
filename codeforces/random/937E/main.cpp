#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;
vector<int> ops, cur, targ, pos[26];
deque<int> cur_seg;

void go(int x) {
    vector<int> v;
    while (x--) {
        v.push_back(cur.back());
        cur.pop_back();
    }
    for (int i : cur)
        v.push_back(i);

    cur.swap(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> s >> t;

    string s_srt = s, t_srt = t;
    sort(s_srt.begin(), s_srt.end());
    sort(t_srt.begin(), t_srt.end());
    if (s_srt != t_srt)
        return cout << "-1\n", 0;

    cur.resize(n); targ.resize(n);
    iota(cur.begin(), cur.end(), 0);
    for (int i = 0; i < n; ++i)
        pos[s[i] - 'a'].push_back(i);
    for (int i = 0; i < n; ++i) {
        targ[i] = pos[t[i] - 'a'].back();
        pos[t[i] - 'a'].pop_back();
    }

    int l = (n - 1) / 2, r = l + 1;
    bool f = 1;
    while (l >= 0 || r < n) {
        int here = (f ? targ[l] : targ[r]);
        if (f)
            cur_seg.push_front(here);
        else
            cur_seg.push_back(here);

        // bring current targ to front
        int here_ind = find(cur.begin(), cur.end(), here) - cur.begin();
        go(n - here_ind);
        ops.push_back(n - here_ind);

        // bring current segment to back
        int bk = n - 1;
        for (; cur[bk] != (f ? cur_seg.back() : cur_seg.front()); --bk);
        ++bk;
        go(n - bk);
        ops.push_back(n - bk);

        // flip entire segment
        go(n);
        ops.push_back(n);

        f ? --l : ++r;
        f ^= 1;
    }

    if (n & 1)
        ops.pop_back();

    int sz = ops.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; ++i)
        cout << ops[i] << " \n"[i == sz - 1];
}
