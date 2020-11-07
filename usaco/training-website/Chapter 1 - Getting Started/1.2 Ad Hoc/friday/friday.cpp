/*
ID: justiny7
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isLeapYear(int A) //True = leap year, false = not leap year
{
	if (((A % 4 == 0) && (A % 100 != 0)) || (A % 400 == 0)) return (true);
	else return (false);
}

int Leap(int A) //Returns # of leap years in A years
{
	int c = 0;
	for (int i = 0; i < A; i++)
	{
		if (isLeapYear(1900 + i) == 1) c++;
	}
	return c;
}

int Days(int A) //Returns # of days in A years
{
	return (365 * A + Leap(A));
}

int main()
{
	ofstream fout("friday.out");
	ifstream fin("friday.in");

	int N; //Number of years
	int thirteen[7] = { 0, 0, 0, 0, 0, 0, 0 }; //Number of times the 13th lands on each day of the week

	int MonthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Number of days in each month
	int MonthDaysL[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Number of days in each month (leap year)
	int moDays[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //Number of days until each 13th in a normal year
	int moDaysL[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //Number of days until each 13th in a leap year
	
	vector <int> moThirteen; //Number of days until each thirteenth overall

	fin >> N;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < i; j++)
		{
			moDays[i] += MonthDays[j];
			moDaysL[i] += MonthDaysL[j];
		}
		moDays[i] += 13;
		moDaysL[i] += 13;
	}
	for (int i = 0; i < N; i++)
	{
		if (i % 100 == 0) cout << endl << i << "\n\n";
		cout << i << " " << isLeapYear(1900 + i) << " ";
		for (int j = 0; j < 12; j++)
		{
			if (isLeapYear(1900 + i) == 1) {moThirteen.push_back(moDaysL[j] + Days(i));
			cout << moDaysL[j] + Days(i) << " " << '\t';}
			else {moThirteen.push_back(moDays[j] + Days(i));
				cout << moDays[j] + Days(i) << "  " << '\t';}
		}
		cout << endl;
	}
	for (int i = 0; i < moThirteen.size(); i++)
	{
		for (int w = 0; w < 7; w++)
		{
			if (w != 6)
			{
				if (moThirteen[i] % 7 == w) thirteen[w + 1] += 1;
			}
			else if (w == 6)
			{
				if (moThirteen[i] % 7 == w) thirteen[0] += 1;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << thirteen[i] << '\t';
		fout << thirteen[i];
		if (i != 6) fout << " ";
	}
	fout << "\n";

	return 0;
}
