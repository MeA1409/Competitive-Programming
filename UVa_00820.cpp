#include <bits/stdc++.h>

using namespace std;

struct edge{
    int v, cap, rev;
    edge(int _v, int _cap, int _rev) : v(_v), cap(_cap), rev(_rev) {}
};

typedef vector <int> vi;
const int N = 101;
const int inf = 0x3f3f3f3f;
vector <edge> Edge;

void addEdge(vi adj[]) {
  int u, v, cap; cin >> u >> v >> cap;
	adj[u].push_back(Edge.size());
	Edge.push_back(edge(v, cap, Edge.size() + 1));
	adj[v].push_back(Edge.size());
	Edge.push_back(edge(u, 0, Edge.size() - 1));
	
	adj[v].push_back(Edge.size());
	Edge.push_back(edge(u, cap, Edge.size() + 1));
	adj[u].push_back(Edge.size());
	Edge.push_back(edge(v, 0, Edge.size() - 1));
}

int bfs(vi adj[], int level[], int s, int t) {
    for (int i = 1; i < N; i++)
        level[i] = 0;
    level[s] = 1;
    queue <int> Q; Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int ind = adj[u][i];
            int v = Edge[ind].v, cap = Edge[ind].cap;
            if (level[v] == 0 && cap > 0) {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
    return level[t] > 0;
}

int sendFlow(vi adj[], int level[], int u, int t, int flow) {
    if (u == t) return flow;
    
    for (int i = 0; i < adj[u].size(); i++) {
        int ind = adj[u][i];
        int v = Edge[ind].v, 
            cap = Edge[ind].cap;
        if (level[v] == level[u] + 1 && cap > 0) {
            int nxtflow = min(flow, cap),
                thisflow = sendFlow(adj, level, v, t, nxtflow);
            if (thisflow > 0) {
                Edge[ind].cap -= thisflow;
                Edge[Edge[ind].rev].cap += thisflow;
                return thisflow;
            }
        }
    }
    return 0;
}

int main() {
    int n; int s = 1;
    while (cin >> n, n > 0) {
      int src, dst, c; cin >> src >> dst >> c;
      Edge.clear();
	    vi adj[N];
	    for (int i = 0; i < c; i++) 
            addEdge(adj);
	    
	    if (src == dst) {
	        cout << "Network " << s++ << endl;
	        cout << "The bandwidth is " << 0 << ".\n";
	        continue;
	    }
	    
	    int tflow = 0; int level[N];
    	while (bfs(adj, level, src, dst)) {
	        while (int flow = sendFlow(adj, level, src, dst, inf))
	            tflow += flow;
	    }
	    cout << "Network " << s++ << endl;
	    cout << "The bandwidth is " << tflow << ".\n\n";
    }
	  return 0;
}
