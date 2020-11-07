//USACO Silver December 2017 Problem 3
#include <bits/stdc++.h>
using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

//keep track of in nodes
int n, ans, num, cows[100001], in[100001];
queue<int> impos;

int main(void) {
    fin >> n;
    ans=n;
    for (int i=0; i<n; i++) {
        fin >> cows[i];
        cows[i]--;
        in[cows[i]]++;
    }
    for (int i=0; i<n; i++) //it's not a possibility if it has 0 in nodes
        if (!in[i]) {
            --ans;
            impos.push(i);
        }
    while (!impos.empty()) {
        int cur=impos.front();
        --in[cows[cur]];
        if (!in[cows[cur]]) { //for each impos, check if child is impos as well
            impos.push(cows[cur]);
            --ans;
        }
        impos.pop();
    }
    fout << ans << '\n';
}
