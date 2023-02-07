#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s) {
	vector<int> pi(s.length());
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main() {

	string s, t;
	cin >> s >> t;
	vector<int> pi = prefixFunction(t);
	int i = 0, j = 0;
	while (i < s.size()) {
		while (j < t.size() && s[(i + j) % s.size()] == t[j]) {
			j++;
		}
		if (j == t.size()) {
			cout << (i + j - 1) / s.size() + 1;
			return 0;
		}
		j = pi[j];
		i += max(1, j - pi[j]);
	}
	cout << -1;

	return 0;
}
//2
#include <iostream>
#include<vector>
using namespace std;

vector<int> prefix(string s) {
	vector<int> pi(s.size());
	for (int i = 1; i < s.size(); i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}
int kmp(string s, string c){
    s = c + "#" + s;
    vector<int> pi = perfix(s);
    for(int i = 0; i < s.size(); i++){
        if(pi[i] == c.size()){
            return i - 2*c.size();
        }
    }
    return -1;
}
int main() {

	string s, c;
	cin >> s >> c;
	vector<int> pi = prefix(c);
	int i = 0
	int j = 0;
	while (i < s.size()) {
		while (j < c.size() && s[(i + j) % s.size()] == c[j]) {
			j++;
		}
		if (j == c.size()) {
			cout << (i + j - 1) / s.size() + 1;
			return 0;
		}
		j = pi[j];
		i += max(1, j - pi[j]);
	}
	cout << -1;

	return 0;
}