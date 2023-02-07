#include <iostream>
#include <vector>
using namespace std;

int lastPrefixFunction(string s){
    vector<int> pi(s.size());
    pi[0] = 0;
    for(int i = 1;i < s.size(); i++){
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]){
            j = pi[j-1];
        }
        if(s[j] == s[i]){
            pi[i] = j + 1;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi[s.size()-1];
}

int main(){
    int t; cin >> t;
    int res[t];
    for(int i = 0; i < t ;i++){
        string s; cin >> s;
        int k; cin >> k;
        int p = lastPrefixFunction(s);
        res[i] = (s.size() - p)* k + p;
    }

    for(int i = 0; i < t; i++){
        cout << res[i] << endl;
    }

    return 0;
}