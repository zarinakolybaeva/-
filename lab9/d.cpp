#include <iostream>
#include <vector>
using namespace std;

bool cmp(char a, char b){
    if(int(b) < 97) return (a != char(int(b) + 32));
    if(int(a) < 97) return (b != char(int(a) + 32));
    return a != b;
}

vector<int> perfixFunction(string s){
    vector<int> pi(s.size());
    pi[0] = 0;
    for(int i = 1;i < s.size(); i++){
        int j = pi[i-1];
        while(j > 0 && cmp(s[j], s[i])){
            j = pi[j-1];
        }
        if(!cmp(s[j], s[i])){
            pi[i] = j + 1;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}

int kmp(string s, string t){
    s = t + "#" + s;
    vector<int> pi = perfixFunction(s);
    return pi[s.size()-1];
}

int main(){
    string s; cin >> s;
    int n; cin >> n;
    string towns[n];
    int reses[n];
    int max = -1;
    int cnt = 0;
    for(int i = 0; i < n ; i++){
        cin >> towns[i];
    }
    for(int i = 0 ; i < n ;i++){
        reses[i] = kmp(s,towns[i]);
        if(reses[i] == max) cnt++;
        if(reses[i] > max){
            max = reses[i];
            cnt = 0;
        }
    }
    if(max > 0){
        cout << cnt+1<< endl;
        for(int i = 0; i < n; i++){
            if(reses[i] == max){
                cout << towns[i] << endl;
            }
        }
    }
    else{
        cout << 0;
    }

    return 0;
}
