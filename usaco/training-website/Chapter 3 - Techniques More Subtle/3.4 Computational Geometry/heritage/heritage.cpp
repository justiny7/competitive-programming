/*
ID: justiny7
LANG: C++
TASK: heritage
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("heritage.in");
ofstream fout("heritage.out");

string inorder, preorder, postorder;
unordered_map<char, pair<bool, bool>> subtrees;
unordered_map<char, pair<char, char>> tree;
int len, counter;

void split() {
	bool ltree = false, rtree = false;
	char root = preorder[counter];
	pair<bool, bool> strees;
	bool found = false;

	for (int i = 0; i < len; i++) {
		if (!found && inorder[i] != ' ' && inorder[i] != root)
			ltree = true;
		if (!found && inorder[i] == ' ')
			ltree = false;
		else if (!found && inorder[i] == root) {
			found = true;
			inorder[i] = ' ';
		}
		else if (found && inorder[i] != ' ')
			rtree = true;
		else if (found && inorder[i] == ' ')
			break;
	}

	subtrees[root] = {ltree, rtree};
}

int visited, Node;
void fillTree() {
	if (Node == len)
		return;

	int curnode = Node;
	if (subtrees[preorder[curnode]].first) {
		tree[preorder[curnode]].first = preorder[++Node];
		fillTree();
	}
	if (subtrees[preorder[curnode]].second) {
		tree[preorder[curnode]].second = preorder[++Node];
		fillTree();
	}
	if (!subtrees[preorder[curnode]].second && !subtrees[preorder[curnode]].first) {
		tree[preorder[curnode]].first = ' ';
		tree[preorder[curnode]].second = ' ';
	}
}

int visited2;
void po_traverse(char node) {
	if (visited2 == len || node == ' ')
		return;

	if (tree.find(tree[node].first) != tree.end())
		po_traverse(tree[node].first);
	if (tree.find(tree[node].second) != tree.end())
		po_traverse(tree[node].second);
	
	visited2++;
	postorder.push_back(node);
}

int main(void) {
	fin >> inorder >> preorder;
	len = preorder.length();

	while (counter < len) {
		split();
		counter++;
	}

	fillTree();
	po_traverse(preorder[0]);
	/*
	for (auto i : subtrees) {
		cout << "root: " << i.first << '\n';
		cout << "ltree: " << i.second.first << '\t';
		cout << "rtree: " << i.second.second << "\n\n";
	}

	for (auto i : tree) {
		cout << "root: " << i.first << '\n';
		cout << "ltree: " << i.second.first << '\t';
		cout << "rtree: " << i.second.second << "\n\n";
	}*/

	fout << postorder << '\n'; 

	return 0;
}
