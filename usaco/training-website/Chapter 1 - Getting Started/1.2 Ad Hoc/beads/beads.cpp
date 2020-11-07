/*
ID: justiny7
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int inARowB(string beads, int start)
{
	int c = 0;
	for (int i = start; beads[i] == 'w' || beads[i] == 'b'; i++)
		c++;
	return c;
}
int inARowR(string beads, int start)
{
	int c = 0;
	for (int i = start; beads[i] == 'w' || beads[i] == 'r'; i++)
		c++;
	return c;
}
int inARowBBack(string beads, int start)
{
	int c = 0;
	for (int i = start; beads[i] == 'w' || beads[i] == 'b'; i--)
		c++;
	return c;
}
int inARowRBack(string beads, int start)
{
	int c = 0;
	for (int i = start; beads[i] == 'w' || beads[i] == 'r'; i--)
		c++;
	return c;
}

int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");

	int N;
	fin >> N;

	vector <int> lengths;

	string beads;
	string beginning;
	fin >> beads;

	int a = 0;
	int b = 0;
	int total = 0;
	int largestTotal = 0;
	bool f = true;

	for (int i = 0; i < N; i++)
	{
		if (beads[i] == 'b')
		{
			f = true;
			break;
		}
		else if (beads[i] == 'r')
		{
			f = false;
			break;
		}
	}
	if (inARowB(beads, 0) == N || inARowR(beads, 0) == N)
	{
		cout << endl << N << endl;
		fout << N << '\n';
	}
	else
	{
		if (f) beginning = beads.substr(0, inARowB(beads, 0));
		else beginning = beads.substr(0, inARowR(beads, 0));
		beads += beginning;
		N += beginning.size();

		int count = 0;
		int marker = 0;

		for (int i = 0; i < N; i = b, count++)
		{
			if (f) a = inARowB(beads, b);
			else a = inARowR(beads, b);

			if (i != 0 && a == 0) break;

			lengths.push_back(a);
			if (lengths.size() > 1) total = lengths[count] + lengths[count - 1];
			cout << lengths[count] << '\t' << total << endl;

			if (total >= largestTotal)
			{
				largestTotal = total;
				marker = i;
			}
			b += a;
			f = !f;
		}

		int temp = 0;
		if (f == false) temp = inARowB(beads, marker) + inARowRBack(beads, marker - 1);
		else if (f == true) temp = inARowR(beads, marker) + inARowBBack(beads, marker - 1);

		if (temp > largestTotal && temp <= N - beginning.size()) largestTotal = temp;
		cout << endl << largestTotal << endl;
		fout << largestTotal << '\n';
	}

	cout << endl;

	return 0;
}