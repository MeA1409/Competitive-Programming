#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair<int, int> pii;
const int inf = (int) 1e9;

struct edge{
    int v, cap, rev;
    edge() {}
    edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
};

void add(vector <int> adj[], vector <edge> &Edge, int u, int v, int cap) {
    adj[u].push_back(Edge.size());
    Edge.push_back(edge(v, cap, Edge.size() + 1));
    adj[v].push_back(Edge.size());
    Edge.push_back(edge(u, 0, Edge.size() - 1));
}

int bfs(vector <int> adj[], vector <edge> &Edge, pii parent[], int n) {
    int vis[n+1] = {0};
    queue<int> Q; Q.push(1);
    vis[1] = 1; parent[1] = pii(-1, -1);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int in = adj[u][i];
            int v = Edge[in].v;
            int cap = Edge[in].cap;
            if (!vis[v] && cap > 0) {
                vis[v] = 1; Q.push(v);
                parent[v] = pii(u, in);
            }
        }
    }
    return vis[2];
}

int Edmonds(vector <int> adj[], vector <edge> &Edge, int n) {
    pii parent[n+1];
    int total = 0;
    while (bfs(adj, Edge, parent, n)) {
        int curflow = inf;
        int v = 2,
            u = parent[v].first;
        while (u != -1) {
            curflow = min(curflow, Edge[parent[v].second].cap);
            v = u, u = parent[v].first;
        }
        v = 2, u = parent[v].first;
        while (u != -1) {
            Edge[parent[v].second].cap -= curflow;
            Edge[Edge[parent[v].second].rev].cap += curflow;
            v = u, u = parent[v].first;
        }
        total += curflow;
    }
    return total;
}

void getSet(vector <int> adj[], vector <edge> &Edge, map <int, int> &Set, int n) {
    int vis[n+1] = {0};
    queue<int> Q; Q.push(1);
    vis[1] = 1; Set[1] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int in = adj[u][i];
            int v = Edge[in].v;
            int cap = Edge[in].cap;
            if (!vis[v] && cap > 0) {
                vis[v] = 1; Q.push(v);
                Set[v] = 1;
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector <int> adj[n+1];
        vector <edge> Edge;
        vector <pii> connect;
        for (int i = 0; i < m; i++) {
            int u, v, d; cin >> u >> v >> d;
            connect.push_back(pii(u, v));
            add(adj, Edge, u, v, d);
            add(adj, Edge, v, u, d);
        }
        Edmonds(adj, Edge, n);
        map <int, int> Set;
        getSet(adj, Edge, Set, n);
        for (int i = 0; i < m; i++) {
        	if (Set[connect[i].first] != Set[connect[i].second])
        		cout << connect[i].first << " " << connect[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}
