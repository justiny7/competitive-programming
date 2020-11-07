//USACO Bronze January 2018 Problem 3

#include <bits/stdc++.h>
using namespace std;

ifstream fin("outofplace.in");
ofstream fout("outofplace.out");

int n, lineup[101], correct[101];

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> lineup[i];
        correct[i] = lineup[i];
    }
    sort(correct, correct+n);
    int answer = 0;
    for (int i = 0; i < n; i++)
        if (correct[i] != lineup[i])
            answer++;
    fout << max(0, answer-1) << '\n';
    return 0;
}
