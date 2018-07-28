#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int inf = (int) 1e9;
int idx[40][40];
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
    idx[u][v] = edges.size();
    edges.push_back(edge(v, cap, edges.size() + 1));

    adj[v].push_back(edges.size());
    idx[v][u] = edges.size();
    edges.push_back(edge(u, 0, edges.size() - 1));

    u = v;
    for (int i = 3; i < line.size()-1; i++) {
        v = line[i] - '0' + 27;
        adj[u].push_back(edges.size());
        idx[u][v] = edges.size();
        edges.push_back(edge(v, cap, edges.size() + 1));

        adj[v].push_back(edges.size());
        idx[v][u] = edges.size();
        edges.push_back(edge(u, 0, edges.size() - 1));
    }
}

int bfs(vector <int> adj[], int parent[],
                            vector <edge> &edges) 
{
    vector <int> vis(40, 0);
    queue <int> Q; Q.push(0);
    parent[0] = -1; vis[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int ind = adj[u][i];
            int v = edges[ind].v,
                cap = edges[ind].cap;
            if (!vis[v] && cap > 0) {
                vis[v] = 1; parent[v] = u;
                Q.push(v);
            }
        }
    }
    return vis[37];
}

int sol(vector <int> adj[], vector <edge> &edges) {
    int parent[40] = {0};
    int max_flow = 0;
    while (bfs(adj, parent, edges)) {
        int v = 37, u = parent[v];
        int flow = inf;
        while (u != -1) {
            flow = min(flow, edges[idx[u][v]].cap);
            v = u; u = parent[v];
        }
        v = 37, u = parent[v];
        while (u != -1) {
            edges[idx[u][v]].cap -= flow;
            edges[idx[v][u]].cap += flow;
            v = u; u = parent[v];
        }
        max_flow += flow;
    }
    return max_flow;
}

int main() {
	string line;
	while (getline(cin, line)) {
	      apps = 0;
	      memset(idx, -1, sizeof(idx));

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
            idx[u][v] = edges.size();
            edges.push_back(edge(v, 1, edges.size() + 1));

            adj[v].push_back(edges.size());
            idx[v][u] = edges.size();
            edges.push_back(edge(u, 0, edges.size() - 1));
        }
        int max_flow = sol(adj, edges);
        if (max_flow != apps) 
            cout << "!\n";
        else {
            for (int i = 0; i < 10; i++) {
                int alloc = -1;
                for (int j = 0; j < 26; j++) {
                    if (edges[idx[i+27][j+1]].cap == 1) 
                        alloc = j;
                }
                if (alloc == -1) cout << '_';
                else cout << (char) ('A' + alloc);
            }
            cout << endl;
        }
	}
	return 0;
}
