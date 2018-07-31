#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int inf = (int) 1e9;
int mat[12][27];

struct edge{
    int v, cap, rev;
    edge(int _v, int _cap, int _rev) : v(_v), cap(_cap), rev(_rev) {}
};

void add(vector <int> adj[], vector <edge> &Edge, int u, int v, int cap) {
    adj[u].push_back(Edge.size());
    Edge.push_back(edge(v, cap, Edge.size() + 1));
    adj[v].push_back(Edge.size());
    Edge.push_back(edge(u, 0, Edge.size() - 1));
}

int bfs(vector <int> adj[], vector <edge> &Edge, pii parent[], int t) {
    int vis[t+1] = {0};
    queue<int> Q; Q.push(0);
    vis[0] = 1; parent[0] = pii(-1, -1);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = Edge[adj[u][i]].v;
            int cap = Edge[adj[u][i]].cap;
            if (!vis[v] && cap > 0) {
                vis[v] = 1; parent[v] = pii(u, adj[u][i]);
                Q.push(v);
            }
        }
    }
    return vis[t];
}

int sol(vector <int> adj[], vector <edge> &Edge, int t) {
    pii parent[t+1];
    int max_flow = 0;
    while (bfs(adj, Edge, parent, t)) {
        int flow = inf;
        int v = t, u = parent[v].first;
        while (u != -1) {
            flow = min(flow, Edge[parent[v].second].cap);
            v = u, u = parent[v].first;
        }
        
        v = t, u = parent[v].first;
        while (u != -1) {
            Edge[parent[v].second].cap -= flow;
            Edge[Edge[parent[v].second].rev].cap += flow;
            v = u, u = parent[v].first;
        }
        max_flow += flow;
    }
    return max_flow;
}
 int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int s = 1; s <= t; s++) {
        memset(mat, 0, sizeof(mat));
        int n, m; cin >> n >> m;
        int sink = n + m + 1; 
        vector <int> adj[sink + 1];
        vector <edge> Edge;
        sink = n + m + 1;
        for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            while (k--) {
                int c; cin >> c;
                mat[i][c]++;
            }
        }
        for (int j = 1; j <= m; j++) {
            add(adj, Edge, 0, j, mat[1][j]);
            add(adj, Edge, j, sink, 1);
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mat[i][j] == 0) 
                    add(adj, Edge, j, i + m, 1);
                else if (mat[i][j] > 1)
                    add(adj, Edge, i + m, j, mat[i][j] - 1);
            }
        }
        int max_flow = sol(adj, Edge, sink);
        cout << "Case #" << s << ": " << max_flow << endl;
    }
}
