#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4 + 7;
const int inf = (int) 0x3c3c3c3c;
typedef pair<int, int> pii;

int main() {
	int t; cin >> t;
	while (t--) {
	    int n, m; cin >> n >> m;
	    vector <pii> adj[n];
	    for (int i = 0; i < m; i++) {
	        int u, v; cin >> u >> v;
	        int t; cin >> t;
	        adj[u].push_back(pii(v, t));
	    }
	    vector <int> dist(n, inf);	dist[0] = 0;
	    vector <int> used(n, 0), in(n, 0); 
	    
	    int neg = 0;
	    queue <int> Q; Q.push(0); in[0] = 1;
	    while (!Q.empty()) {
	        int u = Q.front(); Q.pop(); in[u] = 0;
	        if (used[u] >= n) {
	            neg = 1;
	            break;
	        }
	        for (int j = 0; j < adj[u].size(); j++) {
	            int v = adj[u][j].first;
	            int t = adj[u][j].second;
	            if (dist[v] > dist[u] + t) {
	                dist[v] = dist[u] + t;
	                if (!in[v]) {
	                    used[v]++; in[v] = 1;
	                    Q.push(v);
	                }
	            }
	        }
	    }
	    if (neg) cout << "possible\n";
	    else cout << "not possible\n";
	}
	return 0;
}
