#include <bits/stdc++.h> 
using namespace std; 
int main(){ 

    char c; 
    deque<int> dq; 
    while(cin>>c){ 
        int a; 
        if(c=='+'){ 
            cin >> a; 
            dq.push_front(a); 
        }  
        if(c=='-'){ 
            cin >> a; 
            dq.push_back(a); 
        }  
        if(c=='*'){ 
            if(!dq.empty()){ 
                cout << dq.front()+dq.back() << endl; 
                dq.pop_front(); 
                // if(!dq.empty())
                // dq.pop_back(); 
            } 
            else if(dq.empty()) { 
                cout << "error\n"; 
            } 
        } if(c=='!'){ 
            return 0; 
        } 
    } 
    return 0; 
}