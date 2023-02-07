#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[10000001];
int used[1000001];
vector<int> order;

void dfs(int v, int p = -1){
    used[v] = 1;
    for(int i = 0 ; i < graph[v].size() ;i++){
        int to = graph[v][i];
        if(used[to] == 0){
            dfs(to, v);
        }
        else if(used[to] == 1){
            cout << "Impossible";
            exit(0);
        }
    }
    order.push_back(v+1);
    used[v] = 2;
}

int main(){
    int n, m;  cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x, y; cin >> x >> y;
        graph[x-1].push_back(y-1);
    }
    for(int i = 0; i < n;i++){
        used[i] = 0;
    }

    for (int i = 0; i < n; i++) {  
        if (used[i] == 0) {                 
            dfs(i);                     
        }
    }
    reverse(order.begin(), order.end());
   
    cout << "Possible" << endl;
    for(int i = 0 ; i < order.size(); i++){
        cout << order[i] << " ";
    }

    return 0;
}
//2
#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10000001];
    int used[1000001];
    vector<int> order;
void dfs(int v, int p = -1){
    used[v] = 1;
    for(int i = 0 ; i < graph[v].size() ;i++){
        int to = graph[v][i];
        if(used[to] == 0){
            dfs(to, v);
        }
        else if(used[to] == 1){
            cout << "Impossible";
            return;
        }
    }
    order.push_back(v+1);
    used[v] = 2;
}

int main(){
    
    int n, m; 
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x, y; cin >> x >> y;
        graph[x-1].push_back(y-1);
    }
    for(int i = 0; i < n;i++){
        used[i] = 0;
    }

    for (int i = 0; i < n; i++) {  
        if (used[i] == 0) {                 
            dfs(i);                     
        }
    }
    cout << "Possible" << endl;
    for(int i = order.size()-1; i >=0 ; i--){
        cout << order[i] << " ";
    }

    return 0;
}
    reverse(vec.begin(), vec.end());
    cout << "Possible" << endl;
    for(int i = 0 ; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    //3
    
#include <bits/stdc++.h>
using namespace std;
vector<int> ans[100000];
int vis[100000];
vector<int> vec;
void dfs(int v, int p = -1){
    vis[v] = 1;
    for(int i = 0 ; i < ans[v].size() ;i++){
        int to = ans[v][i];
        if(vis[to] == 0){
            dfs(to, v);
        }
        else if(vis[to] == 1){
            cout << "Impossible";
            exit(0);
        }
    }
    vec.push_back(v+1);
    vis[v] = 2;
}
int main(){
    int n, m;  
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        ans[a-1].push_back(b-1);
    }
    for(int i = 0; i < n;i++){
        vis[i] = 0;
    }

    for (int i = 0; i < n; i++) {  
        if (vis[i] == 0) {                 
            dfs(i);                     
        }
    }
    cout << "Possible" << endl;
    for(int i = vec.size()-1; i >=0 ; i--){
        cout << vec[i] << " ";
    }


}