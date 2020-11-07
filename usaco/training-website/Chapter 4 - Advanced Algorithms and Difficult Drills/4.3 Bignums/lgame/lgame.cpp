/*
ID: justiny7
LANG: C++
TASK: lgame
*/

/*
 * A seemingly intimidating problem at first but it was actually pretty easy, except it took me 3 submissions - the first one because I forgot
 * the cases where it's impossible to fill the entire word, the second because I didn't read directions and put single words before paired words
 *
 * But anyways, fun problem to do - the reason why it took so long was because school but onto chapter 4.4!
*/

//I realized like 80% through that it could only be single words or pairs, so I could've made my life so much easier by using a pair of 
//strings to store my answers instead of a vector but oh well
#include <bits/stdc++.h>
using namespace std;

ifstream fin("lgame.in");
ifstream fwords("lgame.dict"); //haha
ofstream fout("lgame.out");

int ans = -1, maxscore;
string input, alphabet = "abcdefghijklmnopqrstuvwxyz";
vector<pair<string, string>> dictionary;
vector<vector<string>> answers;
unordered_map<char, int> letters, beginnings;
bool vis[40000];

void setMap() {
	string alph = "qwertyuiopasdfghjklzxcvbnm"; //typing this was fun
	int nums[] = {7,6,1,2,2,5,4,1,3,5,2,1,4,6,5,5,7,6,3,7,7,4,6,5,2,5}; //typing this was not
	for (int i = 0; i < 26; i++)
		letters[alph[i]] = nums[i];
}

bool works(string a, string x) {
    int counter = 0;
    for (int i = 0, j = 0; i < a.length(); i++)
        if (a[i] == x[j]) {
            j++;
            if (j == x.length())
                return true;
        }
    return false;
}

string rem(string a, string x) {
    vector<int> where;
    for (int i = 0, j = 0; i < a.length(); i++) {
        if (a[i] == x[j]) {
            where.push_back(i);
            j++;
            if (j == x.length())
                break;
        }
    }
    int t = 0;
    for (int i : where) {
        a.erase(a.begin()+i-t);
        t++;        
    }
    return a;
}

int scoreof(string a) {
    int sc = 0;
    for (int i = 0; i < a.length(); i++)
        sc += letters[a[i]];
    return sc;
}

void dfs(string cur, vector<string> path) {
    if (cur == "" || path.size() == 2) {
        int curscore = maxscore-scoreof(cur);
        if (curscore > ans) {
            answers.clear();
            sort(path.begin(), path.end());
            answers.push_back(path);
            ans = curscore;
        }
        else if (curscore == ans) {
            sort(path.begin(), path.end());
            answers.push_back(path);
        }
        return;
    }
    //cout << cur << '\n';
    vector<string> temp = path;
    bool impos = true;
    for (int i = 0; i < cur.length(); i++)
        if (i == 0 || (i > 0 && cur[i] != cur[i-1])) {
            char orig = cur[i];
            int j = beginnings[orig];
            while (dictionary[j].first[0] == orig) {
                if (!vis[j] && cur.length() >= dictionary[j].first.length() && works(cur, dictionary[j].first)) {
                    impos = false;
                    vis[j] = true;
                    path.push_back(dictionary[j].second);
                    //cout << dictionary[j].second << '\n';
                    //cout << rem(cur, dictionary[j].first) << '\n';
                    dfs(rem(cur, dictionary[j].first), path);
                    path.pop_back();
                    vis[j] = false;
                }
                j++;
            }
        }
    if (impos) {
        int curscore = maxscore-scoreof(cur);
        if (curscore > ans) {
            answers.clear();
            sort(path.begin(), path.end());
            answers.push_back(path);
            ans = curscore;
        }
        else if (curscore == ans) {
            sort(path.begin(), path.end());
            answers.push_back(path);
        }
    }
}

bool sortmeth(vector<string> a, vector<string> b) {
    if (a.size() != b.size())
        return (a.size() > b.size());
    if (a[0] != b[0])
        return (a[0] < b[0]);
    else
        return (a[1] < b[1]);
}

int main(void) {
	setMap();
	fin >> input;
    sort(input.begin(), input.end());
    //cout << input << '\n';
    for (int i = 0; i < input.length(); i++)
        maxscore += letters[input[i]];

	string temp = "";
	while (temp != ".") {
		fwords >> temp;
        string temp2 = temp;
        sort(temp2.begin(), temp2.end());
		dictionary.push_back({temp2, temp});
	}
	dictionary.pop_back(); //pop back the period
    sort(dictionary.begin(), dictionary.end());
    int curlet = 0;
    beginnings['a'] = 0;
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i].first[0] != alphabet[curlet]) {
            curlet++;
            beginnings[alphabet[curlet]] = i;
        }
    }
    /*for (int i = 0; i < 26; i++)
        cout << dictionary[beginnings[alphabet[i]]].first << " " << dictionary[beginnings[alphabet[i]]].second << " " << beginnings[alphabet[i]] << '\n';
    */
    vector<string> asdf;
    dfs(input, asdf);
    fout << ans << '\n';
    sort(answers.begin(), answers.end(), sortmeth);
    for (int i = 0; i < answers.size(); i++) {
        if (i > 0 && answers[i] == answers[i-1])
            continue;
        for (int j = 0; j < answers[i].size(); j++) {
            if (j >= answers[i].size())
                break;
            if (j > 0)
                fout << " ";
            fout << answers[i][j];
        }
        fout << '\n';
    }
    
	return 0;
}
