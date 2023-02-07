#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixFunction(string s){
    vector<int> pi(s.size());
    pi[0] = 0;
    for(int i = 1; i < s.size(); i++){
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]){
            j = pi[j-1];
        }
        if(s[j] == s[i]){
            pi[i] = j+1;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

int kmp(string s, string t){
    s = t + "#" + s;
    vector<int> pi = prefixFunction(s);
    for(int i = 0; i < s.size(); i++){
        if(pi[i] == t.size()){
            return i - 2*t.size();
        }
    }
    return -1;
}

int main(){
    string s, t; cin >> s >>t;
    s = s+s;
    int km = kmp(s,t);// abcdeabcde   decba
    if(km >= 0){
        cout << s.size()/2 - km;
    }
    else{
        cout << km;
    }

    return 0;
}