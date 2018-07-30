#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int inf = (int) 1e9;
const int N = 1025;

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
    int nc, np; 
    while (cin >> nc >> np, nc || np) {
        int sink; int tol = 0;
        vector <int> adj[N];
        vector <edge> Edge;
        sink = nc + np + 1;
        for (int i = 1; i <= nc; i++) {
            int cap; cin >> cap;
            add(adj, Edge, i + np, sink, cap);
            tol += cap;
        }
        for (int i = 1; i <= np; i++) {
            int cats; cin >> cats;
            add(adj, Edge, 0, i, 1);
            for (int k = 0; k < cats; k++) {
                int C; cin >> C;
                add(adj, Edge, i, C + np, inf);
            }
        }
        int max_flow = sol(adj, Edge, sink);
        if (max_flow != tol) cout << 0 << endl;
        else {
            cout << 1 << endl;
            for (int i = 1; i <= nc; i++) {
                int first = 1;
                for (int j = 0; j < adj[i+np].size(); j++) {
                    int ind = adj[i+np][j];
                    if (Edge[ind].cap == 1 && Edge[ind].v != sink) {
                        if (!first) cout << " "; else first = 0;
                        cout << Edge[ind].v;
                    }
                }
                cout << endl;
            }
        }
    }
}
