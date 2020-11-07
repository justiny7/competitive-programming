/*
ID: justiny7
LANG: C++
TASK: camelot
*/

//OHHHH MY GOD FINALLYYY 31 SUBMISSIONS feat. like 10 debug submissions to see if I'm in mem limit -_-
//This is was a true monster - hopefully I got better during this problem lmao

/*
    Plan: go through each knight, use BFS to find least # of moves to each square on the board, go through
    each square on the board and see which has the least min(knight moves + king moves, knight moves + king
    moves to a knight square)
*/

#include <bits/stdc++.h>
#define BIG 1e9
using namespace std;

ifstream fin("camelot.in");
ofstream fout("camelot.out");

struct Knight {
    int row, col; //starting row, col
    int moves[31][27]; //stores min amt of moves to get to square i, j
    //make moves2 which stores min amt of moves to get to square i, j with king (nevermind)
};

int nrow, ncol, kr, kc, moves = BIG, numKnights;
vector<Knight> knights;
int Map[31][27], kingMoves[31][27], cannot[31][27];
bool already[31][27]; //get rid of this (nevermind)
int movesX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int movesY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

//Counts shortest path from knights[index] to every point in the board, as well as filling up the array of whether the king
//can be picked up along the way
void BFS(int index) {
    //Shortest path from knight to each point using BFS
    int nLeft[10000];
    fill(nLeft, nLeft + 10000, 0);
    queue<pair<int, int>> q;
    int counter = 0;
    int kingFound;
    nLeft[counter] = 1;
    q.push({knights[index].row, knights[index].col});
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        nLeft[counter]--;
        if (knights[index].moves[r][c] < 0) {
            knights[index].moves[r][c] = counter;
            if (r == kr && c == kc)
                kingFound = counter;
            for (int i = 0; i < 8; i++) {
                if (r + movesY[i] >= 1 && r + movesY[i] <= nrow && c + movesX[i] >= 1 && c + movesX[i] <= ncol
                    && knights[index].moves[r+movesY[i]][c+movesX[i]] == -1) {
                    q.push({r+movesY[i], c + movesX[i]});
                    knights[index].moves[r+movesY[i]][c+movesX[i]] == -2;
                    nLeft[counter+1]++;
                }
            }
            
        }
        if (nLeft[counter] == 0)
            counter++;
    }

    //Finds out where knight can go after picking up king/fill out already array
    //Already array = is you choose this square, the king won't have to move - it'll be picked up along the way
    bool jumped[31][27];
    for (int i = 1; i <= nrow; i++) {
        for (int j = 1; j <= ncol; j++)
            jumped[i][j] = false;
    }

    queue<pair<int, pair<int, int>>> q2;
    q2.push({kingFound, {kr, kc}});
    //int cnter = 1;
    while (!q2.empty()) {
        int r = q2.front().second.first, c = q2.front().second.second;
        int jump = q2.front().first;
        already[r][c] = true;
        jumped[r][c] = true;
        q2.pop();
        for (int i = 0; i < 8; i++) {
            if (r + movesY[i] >= 1 && r + movesY[i] <= nrow && c + movesX[i] >= 1 && c + movesX[i] <= ncol
                && knights[index].moves[r+movesY[i]][c+movesX[i]] == jump+1
                && !jumped[r+movesY[i]][c+movesX[i]]) {
                q2.push({jump+1, {r+movesY[i], c + movesX[i]}});
                jumped[r+movesY[i]][c+movesX[i]] = true;
                //cnter++;
            }
        }
    }
    //cout << cnter << '\n';
}

//Came in clutch during debugs haha
void printKnights() {
    for (int i = 0; i < numKnights; i++) {
        for (int j = 1; j <= nrow; j++) {
            for (int p = 1; p <= ncol; p++)
                cout << knights[i].moves[j][p] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

int main(void) {
    char temp;
    fin >> nrow >> ncol >> temp >> kr;
    kc = temp - 'A' + 1;
    char a;
    int b;
    while (fin >> a >> b) {
        Knight temp;
        temp.col = a - 'A' + 1;
        temp.row = b;
        knights.push_back(temp);
    }
    numKnights = knights.size();
    /*
    for (int i = 0; i < numKnights; i++) {
        cout << knights[i].row << ", " << knights[i].col << endl;
    }*/

    for (int i = 0; i < numKnights; i++)
        for (int j = 1; j <= nrow; j++)
            for (int p = 1; p <= ncol; p++)
                knights[i].moves[j][p] = -1;
    
    //Shortest path from knight i to every square in the board
    for (int i = 0; i < numKnights; i++)
        BFS(i);
    
    //printKnights();
    
    int movesK = BIG;
    //Find min moves to get the king - whoops forgot kings can move diagonally
    for (int i = 0; i < numKnights; i++) {
        //The king can move up to 2 spaces to make it worth it, so check 3x3 area round king + 2 in each direction
        //nvm kings can move diagonally, check 2 diagonally as well
        int tempMoves;
        if (knights[i].moves[kr][kc] >= 0)
            tempMoves = 2*knights[i].moves[kr][kc];
        else
            tempMoves = BIG;
        //cout << tempMoves << endl;
        if (kc != ncol) {
            if (knights[i].moves[kr][kc+1] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr][kc+1] + 1);
            if (kc < ncol-1 && knights[i].moves[kr][kc+2] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr][kc+2] + 2);
        }
        if (kc > 1) {
            if (knights[i].moves[kr][kc-1] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr][kc-1] + 1);
            if (kc > 2 && knights[i].moves[kr][kc-2] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr][kc-2] + 2);
        }
        if (kr != nrow) {
            if (knights[i].moves[kr+1][kc] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr+1][kc] + 1);
            //cout << tempMoves << endl;
            if (kr < nrow-1 && knights[i].moves[kr+2][kc] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr+2][kc] + 2);
            //cout << tempMoves << endl;
        }
        if (kr > 1) {
            if (knights[i].moves[kr-1][kc] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr-1][kc] + 1);
            if (kr > 2 && knights[i].moves[kr-2][kc] >= 0)
                tempMoves = min(tempMoves, 2*knights[i].moves[kr-2][kc] + 2);
        }
        //diagonal 1
        if (kr > 1 && kc > 1 && knights[i].moves[kr-1][kc-1] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr-1][kc-1] + 1);
        if (kr > 1 && kc < ncol && knights[i].moves[kr-1][kc+1] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr-1][kc+1] + 1);
        if (kr < nrow && kc > 1 && knights[i].moves[kr+1][kc-1] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr+1][kc-1] + 1);
        if (kr < nrow && kc < ncol && knights[i].moves[kr+1][kc+1] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr+1][kc+1] + 1);

        //diagonal 2
        if (kr > 2 && kc > 2 && knights[i].moves[kr-2][kc-2] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr-2][kc-2] + 2);
        if (kr > 2 && kc < ncol-1 && knights[i].moves[kr-2][kc+2] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr-2][kc+2] + 2);
        if (kr < nrow-1 && kc > 2 && knights[i].moves[kr+2][kc-2] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr+2][kc-2] + 1);
        if (kr < nrow-1 && kc < ncol-1 && knights[i].moves[kr+2][kc+2] >= 0)
            tempMoves = min(tempMoves, 2*knights[i].moves[kr+2][kc+2] + 1);

        movesK = min(movesK, tempMoves);
    }
    //cout << "movesK: " << movesK << endl;
    
    //moves for king to get to a square in the board
    for (int i = 1; i <= nrow; i++)
        for (int j = 1; j <= ncol; j++)
            kingMoves[i][j] = abs(kr-i)+abs(kc-j);

    int ans = BIG;

    //Fills out board with num of moves to every square in the board/if square can't be reached
    for (int i = 0; i < numKnights; i++)
        for (int R = 1; R <= nrow; R++)
            for (int C = 1; C <= ncol; C++) {
                if (knights[i].moves[R][C] < 0) {
                    cannot[R][C]++;
                    continue;
                }
                Map[R][C] += knights[i].moves[R][C];
            }

    //Goes through board - min dist for square i is min(only knight moves + only king moves, only knight moves + moves for a knight to get the king)
    for (int i = 1; i <= nrow; i++) {
        for (int j = 1; j <= ncol; j++) {
            if (cannot[i][j] == numKnights)
                continue;
            int temp = movesK;
            if (already[i][j])
                temp = 0;
            int dist = min(Map[i][j] + kingMoves[i][j], Map[i][j] + temp);
            //cout << i << ", " << j << ": " << dist << endl;
            ans = min(dist, ans);
        }
    }
    //If there are no knights, then just select the square the king is on
    if (numKnights == 0)
        ans = 0;
    /*
    for (int i = 1; i <= nrow; i++) {
        for (int j = 1; j <= ncol; j++)
            cout << already[i][j] << " ";
        cout << endl;
    }*/

    fout << ans << endl;
      
    
    return 0;
}
