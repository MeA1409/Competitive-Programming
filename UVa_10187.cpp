#include <bits/stdc++.h>

using namespace std;

struct edge{
    int v, dep;
    int t;
    edge(int _v, int _dep, int _t) : v(_v), dep(_dep), t(_t) {}
};

typedef pair<int, int> ii;

int main() {
	int t; cin >> t;
	for (int s = 1; s <= t; s++) {
	    int q; cin >> q;
	    map <string, int> Midx;
	    vector <edge> adj[107];
	    int idx = 0;
	    while (q--) {
	        string U, V; 
	        cin >> U >> V;
	        int dep, t; 
	        cin >> dep >> t;
	        if (!Midx[U]) Midx[U] = idx++;
	        if (!Midx[V]) Midx[V] = idx++;
	        int u = Midx[U], v = Midx[V];
	        if (dep < 18) dep += 24;
	        if (dep + t > 30) continue;
	        adj[u].push_back(edge(v, dep, t));
	    }
	    string S, E; cin >> S >> E;
	    int st = Midx[S], end = Midx[E];
	    
	    priority_queue<pair<int, ii>, 
	                    vector <pair<int, ii>>, 
	                    greater<pair<int, ii>>> Q;
        int dist[idx+1][31];
        memset(dist, 63, sizeof(dist));
        int inf = dist[0][0];
        
        for (int i = 18; i <= 30; i++)
            dist[st][i] = 0;
        Q.push(make_pair(0, ii(st, 18)));
        while (!Q.empty()) {
            pair<int, ii> T = Q.top(); Q.pop();
            int u = T.second.first, arrv = T.second.second;
            if (dist[u][arrv] != T.first)
                continue;
            for (int j = 0; j < adj[u].size(); j++) {
                edge e = adj[u][j];
                int sleep = 0;
                if (arrv > e.dep) sleep++;
                if (dist[e.v][e.dep + e.t] > dist[u][arrv] + sleep) {
                    dist[e.v][e.dep + e.t] = dist[u][arrv] + sleep;
                    Q.push(make_pair(dist[e.v][e.dep + e.t], ii(e.v, e.dep + e.t)));
                }
            }    
        }
        int m = inf;
        for (int i = 18; i <= 30; i++)
            m = min(m, dist[end][i]);
        
        cout << "Test Case " << s << ".\n";
        if (m == inf)
            cout << "There is no route Vladimir can take.\n";
        else 
            cout << "Vladimir needs " << m << " litre(s) of blood.\n";
	}
	return 0;
}
