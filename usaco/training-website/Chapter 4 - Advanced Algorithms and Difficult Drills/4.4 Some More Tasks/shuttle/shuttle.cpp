/*
ID: justiny7
LANG: C++
TASK: shuttle
*/

/*
 * First things I noticed: same-colored marbles cannot jump over each other, so the indiviudal order of marbles are maintained throughout the entire
 * game. Thus, to check if the state is done, see if the last marble is in their respective positions, and all the others will be as well
 *
 * Strategy: keep marbles of same color either next to each other on the very edges, or spaced 1 apart - shift as many white marbles r in one go
 * retaining the previously described state, then left, then r, etc., until state is complete (I think this is the optimal strategy)
 */

//Ay the strat actually worked (basically) first try!! (cuz I forgot to delete a stray line of testing code so I got it on the second submission)

#include <bits/stdc++.h>
using namespace std;

ifstream fin("shuttle.in");
ofstream fout("shuttle.out");

int n, counter, wpos[21], bpos[21];
bool r = true;
vector<int> moves;
string state, target;

void moveLeft() {
    for (int i = 0; i < n; i++) {
        if (bpos[i] == i)
            continue;
        if (state[bpos[i]-1] == ' ' && state[bpos[i]-2] != 'B' || bpos[i]-1 == i) {
            moves.push_back(bpos[i]+1);
            bpos[i]--;
            state[bpos[i]+1] = ' ';
            state[bpos[i]] = 'B';
        }
        else if (state[bpos[i]-1] == 'W' && state[bpos[i]-2] == ' ') {
            moves.push_back(bpos[i]+1);
            bpos[i] -= 2;
            state[bpos[i]+2] = ' ';
            state[bpos[i]] = 'B';
        }
    }
}

void moveRight() {
    for (int i = 0; i < n; i++) {
        if (wpos[i] == n*2-i)
            continue;
        if (state[wpos[i]+1] == ' ' && state[wpos[i]+2] != 'W' || wpos[i]+1 == n*2-i) {
            moves.push_back(wpos[i]+1);
            wpos[i]++;
            state[wpos[i]-1] = ' ';
            state[wpos[i]] = 'W';
        }
        else if (state[wpos[i]+1] == 'B' && state[wpos[i]+2] == ' ') {
            moves.push_back(wpos[i]+1);
            wpos[i] += 2;
            state[wpos[i]-2] = ' ';
            state[wpos[i]] = 'W';
        }
    }
}

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        state.append("W");
        wpos[i] = n-i-1;
    }
    state.append(" ");
    for (int i = 0; i < n; i++) {
        state.append("B");
        bpos[i] = n+i+1;
    }
    target = state;
    reverse(target.begin(), target.end());
    while (state != target) {
        if (r)
            moveRight();
        else
            moveLeft();
        r = !r;
    }
    for (int i = 0; i < moves.size(); i++) {
        if (i > 0 && i%20 == 0 && i != moves.size()-1)
            fout << '\n';
        fout << moves[i];
        if (i%20 < 19 && i != moves.size()-1)
            fout << " ";
    }
    fout << '\n';
	return 0;
}
