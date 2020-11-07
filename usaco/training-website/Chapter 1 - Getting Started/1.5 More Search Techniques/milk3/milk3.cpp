/*
ID: justiny7
LANG: C++
TASK: milk3
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

int A, B, C;
bool vis[21][21][21];

void pour(int a, int b, int c) {
    //cout << a << " " << b << " " << c << '\n';
    if (!vis[a][b][c]) {
        vis[a][b][c] = true;
        if (a < B-b)
            pour(0, b+a, c);
        else
            pour(a-B+b, B, c);
        if (a < C-c)
            pour(0, b, c+a);
        else
            pour(a-C+c, b, C);
        
        if (b < A-a)
            pour(a+b, 0, c);
        else
            pour(A, b-A+a, c);
        if (b < C-c)
            pour(a, 0, c+b);
        else
            pour(a, b-C+c, C);
        
        if (c < B-b)
            pour(a, b+c, 0);
        else
            pour(a, B, c-B+b);
        if (c < A-a)
            pour(a+c, b, 0);
        else
            pour(A, b, c-A+a);
    }
}

int main(void) {
    fin >> A >> B >> C;
    pour(0, 0, C);
    vector<int> ans;
    for (int i = 0; i <= B; i++)
        for (int j = 0; j <= C; j++)
            if (vis[0][i][j])
                ans.push_back(j);
    
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0)
            fout << ans[i];
        else
            fout << " " << ans[i];
    }
    fout << '\n';
    return 0;
}
