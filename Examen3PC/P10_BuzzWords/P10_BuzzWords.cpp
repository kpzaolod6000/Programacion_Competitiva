#include <bits/stdc++.h>
using namespace std; 

#define size_alpha 26
inline int mp(char c) { return c - 'A'; }

class Node {
public:
    Node *ch[size_alpha];
	int c = 0;
	int d = 0;
	Node() {
		for (int i = 0; i < size_alpha; ++i) ch[i] = NULL;
	}
	
	void insert_chr(string &s, int i = 0) {
		while (i < s.length() && s[i] == ' ') i++;
		if (i == s.length()) { c++; return; }
		else {
			c++;
			int v = mp(s[i]);
			if (ch[v] == NULL) {
				ch[v] = new Node();
				ch[v]->d = d + 1;
			}
			ch[v]->insert_chr(s, i + 1);
		}
	}
	void cleanup() {
		for (int i = 0; i < size_alpha; ++i) {
			if (ch[i] != NULL) ch[i]->cleanup();
			delete ch[i];
		}
	}
	void count(vector<int> &count) {
		count[d] = max(c, count[d]);
		for (int i = 0; i < size_alpha; ++i)
			if (ch[i] != NULL)
				ch[i]->count(count);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string text;
	while (getline(cin, text)) {
		if (text.length() == 0) break;
		Node root;
		for (int i = 0; i < text.length(); ++i)
			if (text[i] != ' ')
				root.insert_chr(text, i);
		
		vector<int> dpth_text(text.length() + 3, 0);
		root.count(dpth_text);
		for (int i = 1; i <= text.length() + 1; ++i) {
			if (dpth_text[i] > 1) cout << dpth_text[i] << endl;
			else {
				cout << endl;
				break;
			}
		}
	}
	
	return 0;
}