#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int inf = (int) 1e9;
int apps;

struct edge{
    int v, cap, rev;
    edge(int _v, int _cap, int _rev) : v(_v), cap(_cap), rev(_rev) {}
};

void add(vector <int> adj[], vector <edge> &edges, string &line) {
    int u, v, cap;
    u = 0;  v = line[0] - 'A' + 1;
    cap = line[1] - '0';
    apps += cap;
    
    adj[u].push_back(edges.size());
    edges.push_back(edge(v, cap, edges.size() + 1));
    adj[v].push_back(edges.size());
    edges.push_back(edge(u, 0, edges.size() - 1));
    
    u = v;
    for (int i = 3; i < line.size()-1; i++) {
        v = line[i] - '0' + 27;
        adj[u].push_back(edges.size());
        edges.push_back(edge(v, cap, edges.size() + 1));
        adj[v].push_back(edges.size());
        edges.push_back(edge(u, 0, edges.size() - 1));
    }
}
 int bfs(vector <int> adj[], pii parent[],
                            vector <edge> &edges) 
{
    vector <int> vis(40, 0);
    queue <int> Q; Q.push(0);
    parent[0] = pii(-1, -1); vis[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int ind = adj[u][i];
            int v = edges[ind].v,
                cap = edges[ind].cap;
            if (!vis[v] && cap > 0) {
                vis[v] = 1; parent[v] = pii(u, ind);
                Q.push(v);
            }
        }
    }
    return vis[37];
}
 int sol(vector <int> adj[], vector <edge> &edges) {
    pii parent[40];
    int max_flow = 0;
    while (bfs(adj, parent, edges)) {
        int flow = inf;

        int v = 37, u = parent[v].first;
        int ind = parent[v].second;
        while (u != -1) {
            ind = parent[v].second;
            flow = min(flow, edges[ind].cap);
            v = u; u = parent[v].first;
        }
        v = 37, u = parent[v].first;
        while (u != -1) {
            ind = parent[v].second;
            edges[ind].cap -= flow;
            edges[edges[ind].rev].cap += flow;
            v = u; u = parent[v].first;
        }
        max_flow += flow;
    }
    return max_flow;
}
 int main() {
	string line;
	while (getline(cin, line)) {
        apps = 0;
        vector <int> adj[40]; 
        vector <edge> edges;
        add(adj, edges, line);
        
        while (getline(cin, line)) {
            if (line.size() == 0) break;
            add(adj, edges, line);
        }
        for (int i = 27; i < 37; i++) {
            int u = i, v = 37;
            adj[u].push_back(edges.size());
            edges.push_back(edge(v, 1, edges.size() + 1));
            adj[v].push_back(edges.size());
            edges.push_back(edge(u, 0, edges.size() - 1));
        }
        int max_flow = sol(adj, edges);
        if (max_flow != apps) 
            cout << "!\n";
        else {
            for (int i = 0; i < 10; i++) {
                int alloc = -1;
                for (int j = 0; j < adj[i+27].size(); j++) {
                    int ind = adj[i+27][j];
                    if (edges[ind].v != 37 && edges[ind].cap == 1)
                            alloc = edges[ind].v - 1;
                }
                if (alloc == -1) cout << '_';
                else cout << (char) ('A' + alloc);
            }
            cout << endl;
        }
	}
	return 0;
}
