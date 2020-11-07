//USACO Silver US Open 2018

#include <bits/stdc++.h>
using namespace std;

ifstream fin("sort.in");
ofstream fout("sort.out");

int n;
vector<int> arr, correct;
bool used[100001];

int main(void) {
    fin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
        correct.push_back(arr[i]);
    }
    sort(correct.begin(), correct.end());
    int maxdif = -1, curdif;
    for (int i = 0; i < n; i++) {
        int lb = lower_bound(correct.begin(), correct.end(), arr[i])-correct.begin();
        while (used[lb])
            lb++;
        used[lb] = true;
        curdif = i-lb;
        if (curdif < 0) //If it has to move right, it gets there immed
            curdif = 1;
        maxdif = max(curdif, maxdif);
    }
    fout << maxdif+1  << '\n';
    return 0;
}
