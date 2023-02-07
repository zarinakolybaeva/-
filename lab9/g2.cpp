#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(string s) {
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
 string s;
 cin >> s;
 vector<int> pi = prefix(s);
 cout << s.size() - pi.back();
 return 0;
}