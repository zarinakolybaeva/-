#include <iostream>
#include <vector>
using namespace std;

vector<int> perfixFunction(string s){
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
    return pi;
}

int main(){
    string s;
    cin >> s;
    vector<int> pref = perfixFunction(s);
    int max = 0;
    for(int i = 0 ; i < pref.size(); i++){
        if(max < pref[i]) max = pref[i];
    }
    if(max == pref[s.size()-1]){
        cout << s.size() - max;
    }else{
        cout << s.size()- pref[s.size()-1];
    }

    return 0;
}