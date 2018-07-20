#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define se second
#define fi first

const int inf = (int) 1e9;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int main() {
    int n, k;
    string line;
	while (cin >> n >> k) {
        getline(cin, line);
        vector <int> Time(n);
	    vector <pair<int, pii>> adj[100];
	    for (int i = 0; i < n; i++)
	        cin >> Time[i];
	    getline(cin, line);
	    for (int i = 0; i < n; i++) {
	        getline(cin, line);
	        stringstream ss;
	        vector <int> floors;
	        ss << line; int u;
	        while (ss >> u) 
	            floors.push_back(u);
	 
	        for (int j = 0; j < floors.size(); j++) {
	            for (int k = j+1; k < floors.size(); k++) {
	                adj[floors[j]].push_back(mp(floors[k], pii((floors[k] - floors[j])*Time[i], i)));
	                adj[floors[k]].push_back(mp(floors[j], pii((floors[k] - floors[j])*Time[i], i)));
	            }
	        }
	    }
	    priority_queue<piii, vector <piii>, greater<piii>> Q;
	    vector <int> dist(100, inf);
	    Q.push(mp(0, pii(0, -1)));
	    dist[0] = 0;
	    while (!Q.empty()) {
	        piii T = Q.top(); Q.pop();
	        int u = T.se.fi, used = T.se.se;
	        if (dist[u] != T.first) continue;
	        for (int i = 0; i < adj[u].size(); i++) {
	            piii nxt = adj[u][i];
	            int v = nxt.first, w = nxt.se.fi;
	            int nxtUsed = nxt.se.se;
                if (nxtUsed != used && used != -1) w+=60;
	            if (dist[v] > dist[u] + w) {
	                dist[v] = dist[u] + w;
	                Q.push(mp(dist[v], pii(v, nxtUsed)));
	            }
	        }
	    }
	    if (dist[k] != inf)
	        cout << dist[k] << endl;
	    else cout << "IMPOSSIBLE\n";
	}
	return 0;
}
