#include <bits/stdc++.h>
using namespace std;
vector<int> vec[500];
int vis[500];
stack<int> st;
vector<int> trail;
bool dfs(int v, int a, int b) {
    vis[v] = 1;
    for (int i = 0; i < vec[v].size(); i++) {
        int to = vec[v][i];
        if (v == a && b == to) continue;
        if (!vis[to]) {
            if (dfs(to, a, b)) return true;
        } else if (vis[to] == 1) {
            return true;
        }
    }
    
    vis[v] = 2;
    return false;
}

bool ans(int v) {
    vis[v] = 1;
    st.push(v);
    for (int i = 0; i < vec[v].size(); i++) {
        int to = vec[v][i];
        if (!vis[to]) {
            if (ans(to)) return true;
        } else if (vis[to] == 1) {
            while (st.top() != to) {
                trail.push_back(st.top());
                st.pop();
            }
            trail.push_back(to);
            trail.push_back(v);
            reverse(trail.begin(), trail.end());
            return true;
        }
    }
    vis[v] = 2;
    if (!st.empty()) st.pop();
    return false;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u;
        int v;
        cin >> u >> v;
        vec[u].push_back(v);
    }
    bool this = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            this = ans(i);
            if (this) 
            break;
        }
    }
    
    if (!this) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < trail.size() - 1; i++) {
        int u = trail[i];
        int v = trail[i + 1];
        for (int j = 1; j <= n; j++) {
            vis[j] = 0;
        }
        this = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                this |= dfs(j, u, v);
            }
        }
        if (!this) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout <<"NO"<< endl;
}
