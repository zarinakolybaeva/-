#include <iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> vec[5005];
bool vis[5005];
int x[5005];
int theme[5005];
int n,m,q;

void bfs(int s) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    queue<int> q;
    q.push(s);
    x[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < vec[v].size(); i++) {
            int to = vec[v][i];
            if (x[to] > x[v] + 1) {
                x[to] = x[v] + 1;
                vis[to] = 1;
                q.push(to);
            }
        }
    }
}

int main() {
    
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u;
        int v; 
        cin >> u >> v;
        vec[v].push_back(u);
        vec[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        x[i] = 1e9;
    }
    for (int t = 1; t <= q; t++) {
        int pi;
        int v;
        cin >> pi >> v;
        if (pi == 1) {
            if (theme[v] != 1) {
                bfs(v);
                theme[v] = 1;
            }
        } else {
            if (x[v] == 1e9) {
                cout << -1 << endl;
            } else {
                cout << x[v] << endl;
            }
        }
    }
}
