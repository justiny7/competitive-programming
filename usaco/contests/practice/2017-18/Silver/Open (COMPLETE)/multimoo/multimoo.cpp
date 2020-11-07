//USACO Silver US Open 2018 Problem 3

#include <bits/stdc++.h>
using namespace std;

ifstream fin("multimoo.in");
ofstream fout("multimoo.out");

int n, board[251][251], groups[251][251], tgroups[251][251], teamnum = 1, groupnum = 1, cursize, singlemax, teammax;
bool u1, u2;
vector<pair<int, int>> lteams; //largest teams
map<int, int> teams;

void dfs(int x, int y, int num, int label) {
    if (groups[x][y] != -1 || board[x][y] != num)
        return;
    cursize++;
    groups[x][y] = label;
    if (x < n-1)
        dfs(x+1, y, num, label);
    if (x > 0)
        dfs(x-1, y, num, label);
    if (y < n-1)
        dfs(x, y+1, num, label);
    if (y > 0)
        dfs(x, y-1, num, label);
}

void dfs2(int x, int y, int num1, int num2, int label) {
    if (tgroups[x][y] != -1 || (board[x][y] != num1 && board[x][y] != num2))
        return;
    cursize++;
    if (board[x][y] == num1)
        u1 = true;
    if (board[x][y] == num2)
        u2 = true;
    tgroups[x][y] = label;
    if (x < n-1)
        dfs2(x+1, y, num1, num2, label);
    if (x > 0)
        dfs2(x-1, y, num1, num2, label);
    if (y < n-1)
        dfs2(x, y+1, num1, num2, label);
    if (y > 0)
        dfs2(x, y-1, num1, num2, label);
}

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> board[i][j];
    memset(groups, -1, sizeof(groups));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cursize = 0;
            teams[board[i][j]]++;
            if (groups[i][j] == -1) {
                dfs(i, j, board[i][j], groupnum++);
                singlemax = max(cursize, singlemax);
            }
            //cout << board[i][j] << " " << cursize << '\n';
        }
    for (pair<int, int> p : teams)
        lteams.push_back({p.second, p.first});
    sort(lteams.begin(), lteams.end(), greater<pair<int, int>>());
    //for (auto i : lteams)
        //cout << i.first << " " << i.second << '\n';
    int i = 0, j = 1;
    for (int o = 0; o < lteams.size()*lteams.size(); o++) {
        //cout << lteams[i].second << " " << lteams[j].second << '\n';
        int curpos;
        if (o > 0) {
            if (j-i == 2)
                i++;
            else
                j++;
        }
        curpos = lteams[j].first+lteams[i].first;
        //cout << curpos << '\n';
        if (curpos <= teammax)
            break;
        memset(tgroups, -1, sizeof(tgroups));
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++) {
                cursize = teamnum = 0;
                u1 = u2 = false;
                if (tgroups[a][b] == -1 && (board[a][b] == lteams[i].second || board[a][b] == lteams[j].second)) {
                    dfs2(a, b, lteams[i].second, lteams[j].second, teamnum++);
                    //cout << u1 << " " << u2 << '\n';
                    if (u1 && u2)
                        teammax = max(teammax, cursize);
                }
            }
    }
    fout << singlemax << '\n' << teammax << '\n';
    return 0;
}
