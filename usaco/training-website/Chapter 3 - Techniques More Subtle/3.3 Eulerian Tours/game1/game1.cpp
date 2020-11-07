/*
ID: justiny7
LANG: C++
TASK: game1
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("game1.in");
ofstream fout("game1.out");

int N, p1, p2, dp[201][201];
bool oneTurn = true;
vector<int> board;
bool seq[201][201]; //true = left, false = right

void add(int a) {
    if (oneTurn)
        p1 += a;
    else
        p2 += a;
    oneTurn = !oneTurn;
}

int solve(int left, int right) {
	if (dp[left][right] != 0)
		return dp[left][right];

	if (left == right) {
		seq[left][right] = true;
		dp[left][right] = board[left];
		return board[left];
	}
	else if (right-left == 1) {
		if (board[left] > board[right]) {
			seq[left][right] = true;
			dp[left][right] = board[left];
			return board[left];
		}
		else {
			seq[left][right] = false;
			dp[left][right] = board[right];
			return board[right];
		}
	}

	int lprofit, rprofit;
	lprofit = board[left] - solve(left + 1, right);
	rprofit = board[right] - solve(left, right - 1);
	//cout << "from " << left << " to " << right << ",\n";
	//cout << "left profit is " << lprofit << "\nand right profit is " << rprofit << "\n\n";
	if (lprofit > rprofit) {
		seq[left][right] = true;
		dp[left][right] = lprofit;
		return lprofit;
	}
	seq[left][right] = false;
	dp[left][right] = rprofit;
	return rprofit;
}

int main(void) {
    fin >> N;
    board.resize(N);
    for (int i = 0; i < N; i++)
        fin >> board[i];
    
	int i = 0, j = N - 1;
	solve(i, j);
	while (i <= j) {
		//cout << solve(i, j) << '\n';
		//add(dp[i][j]);
		
		if (seq[i][j]) {
			add(board[i]);
			i++;
		}
		else {
			add(board[j]);
			j--;
		}
	}
	fout << p1 << " " << p2 << '\n';
	/*cout << "\n\n\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << dp[i][j] << "\t";
		cout << '\n';
	}*/
    return 0;
}