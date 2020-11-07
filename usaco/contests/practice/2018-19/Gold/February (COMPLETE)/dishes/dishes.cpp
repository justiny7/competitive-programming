//Got impl hint from solution
#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, cur, placed[mxN];
stack<int> dirty[mxN];

int main() {
    ifstream cin("dishes.in");
    ofstream cout("dishes.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (a<cur) {
            cout << i << '\n';
            return 0;
        }
        for (int j=a; j>0 && !placed[j]; --j) //all unplaced plates <= cur plate goes in this stack
            placed[j]=a;
        while (!dirty[placed[a]].empty() && dirty[placed[a]].top()<a) //pop plates off of this stack until we can place this plate
            cur=dirty[placed[a]].top(), dirty[placed[a]].pop();
        dirty[placed[a]].push(a);
    }
}

