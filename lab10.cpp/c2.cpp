#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <queue> 
using namespace std; 
 
const int N=(int)1e5+7; 
const int inf=(int)1e9; 
int n, m, st; 
int g[N]; 
int d[N]; 
 
int main(){ 
     
    int a, b; 
    cin>>a>>b; 
 
    queue<int> q; 
    q.push(a); 
    d[a]=1; 
    g[a]=-1; 
    while(!q.empty()){ 
        int v=q.front(); 
        q.pop(); 
        if(v*2 <= 1e4 && !d[v*2]){ 
      q.push(v*2); 
      g[v*2] = v; 
      d[v*2] = d[v] + 1; 
    } 
    if(v-1 > 0 && !d[v-1]){ 
     q.push(v-1); 
      g[v-1] = v; 
      d[v-1] = d[v] + 1;   
    } 
         
    } 
    cout<<d[b]-1<<'\n'; 
 
    vector <int> res; 
 while(g[b] != -1){ 
   res.push_back(b); 
   b = g[b]; 
 } 
 reverse(res.begin(), res.end()); 
 for(int i=0; i<res.size(); i++) cout << res[i] << ' '; 
    return 0; 
}
//2
#include <bits/stdc++.h>
using namespace std; 
const int N=(int)1e5+7; 
const int inf=(int)1e9; 
int n, m, st; 
int g[N]; 
int d[N]; 
int main(){ 
    int a, b; 
    cin>>a>>b; 
    deque<int> d; 
    d.push_back(a); 
    d[a]=1; 
    g[a]=-1; 
    while(!d.empty()){ 
        int v=d.front(); 
        d.pop_back(); 
        if(v*2 <= 1e4 && !d[v*2]){ 
      d.push_back(v*2); 
      g[v*2] = v; 
      d[v*2] = d[v] + 1; 
    } 
    if(v-1 > 0 && !d[v-1]){ 
     d.push_back(v-1); 
      g[v-1] = v; 
      d[v-1] = d[v] + 1;   
    } 
         
    } 
    cout<<d[b]-1<<'\n'; 
    vector <int> res; 
    while(g[b] != -1){ 
   res.push_back(b); 
   b = g[b]; 
 } 
 reverse(res.begin(), res.end()); 
 for(int i=0; i<res.size(); i++) 
 cout << res[i] << ' '; 
}
//3
#include <bits/stdc++.h>
using namespace std; 
const int N=(int)1e5+7; 
const int inf=(int)1e9; 
int n, m, st; 
int g[N]; 
int d[N]; 
int main(){ 
    int a, b; 
    cin>>a>>b; 
    deque<int> d; 
    d.push_back(a); 
    d[a]=1; 
    g[a]=-1; 
    while(!d.empty()){ 
        int v=d.front(); 
        d.pop_back(); 
        if(v*2 <= 1e4 && !d[v*2]){ 
      d.push_back(v*2); 
      g[v*2] = v; 
      d[v*2] = d[v] + 1; 
    } 
    if(v-1 > 0 && !d[v-1]){ 
     d.push_back(v-1); 
      g[v-1] = v; 
      d[v-1] = d[v] + 1;   
    } 
         
    } 
    cout<<d[b]-1<<endl; 
    vector <int> res; 
    while(g[b] != -1){ 
   res.push_back(b); 
   b = g[b]; 
 } 
 //reverse(res.begin(), res.end()); 
 for(int i=res.size()-1; i>=0; i--) 
 cout << res[i] << ' '; 
}
//4
#include <bits/stdc++.h>
using namespace std; 
const int N=(int)1e5+7; 
int n, m; 
int ki[N]; 
int ci[N]; 
int main(){ 
    vector <int> vec; 
    int a, b; 
    cin>>a>>b; 
    deque<int> deq; 
    deq.push_back(a); 
    ci[a]=1; 
    ki[a]=-1; 
    while(!deq.empty()){ 
        int pi=deq.front(); 
        deq.pop_back(); 
        if(pi*2 <= 1e4 && !ci[pi*2]){ 
      deq.push_back(pi*2); 
      ki[pi*2] = pi; 
      ci[pi*2] = ci[pi] + 1; 
    } 
    if(pi-1 > 0 && !ci[pi-1]){ 
     deq.push_back(pi-1); 
      ki[pi-1] = pi; 
      ci[pi-1] = ci[pi] + 1;   
    } 
         
    } 
    cout<<ci[b]-1<<endl; 

 while(ki[b] != -1){ 
   vec.push_back(b); 
   b = ki[b]; 
 } 
 reverse(vec.begin(), vec.end()); 
 for(int i=0; i<vec.size(); i++) 
 cout << vec[i] << ' '; 

}
//5
#include <bits/stdc++.h>
using namespace std; 

int main(){ 
const int N=(int)1e5+7; 
int n, m; 
int ci[N]; 
int ki[N]; 
int a, b; 
cin>>a>>b; 
vector <int> vec;
queue<int> que; 
    que.push(a); 
    ki[a]=1; 
    ci[a]=-1; 
    while(!que.empty()){ 
        int v=que.front(); 
        que.pop(); 
        if(v*2 <= 1e4 && !ki[v*2]){ 
      que.push(v*2); 
      ci[v*2] = v; 
      ki[v*2] = ki[v] + 1; 
    } 
    if(v-1 > 0 && !ki[v-1]){ 
     que.push(v-1); 
      ci[v-1] = v; 
      ki[v-1] = ki[v] + 1;   
    } 
         
    } 
    cout<<ki[b]-1<<endl;  
 while(ci[b] != -1){ 
   vec.push_back(b); 
   b = ci[b]; 
 } 
 reverse(vec.begin(), vec.end()); 
 for(int i=0; i<vec.size(); i++) 
 cout << vec[i] << ' '; 
}