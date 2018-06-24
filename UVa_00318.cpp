#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int inf = (int) 1e9;

typedef pair<int, int> pii;

class Graph{
    int V;
    list <pii> *adj;
    public:
        Graph(int _V) : V(_V) {
            adj = new list <pii>[V];
        }
        void Edge(int u, int v, int w) {
            adj[u].push_back(pii(v, w));
            adj[v].push_back(pii(u, w));
        }
        void sol() {
            vector <int> dist(V, inf), visited(V, 0);
            priority_queue <pii, vector <pii>, greater<pii>> Q;
            dist[0] = 0;
            
            pii Res = pii(1, -1);
            double Time = 0.0;
            
            Q.push(pii(0, 0));
            while (!Q.empty()) {
                pii T = Q.top(); Q.pop();
                
                int u = T.second;
                if (visited[u]) 
                    continue;
                    
                visited[u] = 1;
                if (T.first > Time) {
                    Time = T.first;
                    Res = pii(u + 1, -1);
                }
                
                for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
                    int v = (*i).first, 
                        w = (*i).second;
                    if (visited[v]) {
                        if ((dist[u] + dist[v] + w)*1.0/2 > Time) {
                            Time = (dist[u] + dist[v] + w)*1.0/2;
                            Res = pii(v + 1, u + 1);
                        }
                    }
                    else {
                        if (dist[u] + w < dist[v]) {
                            dist[v] = dist[u] + w;
                            Q.push(pii(dist[v], v));
                        }
                    }
                }
            }
            cout << "The last domino falls after " << fixed << setprecision(1) << Time << " seconds, ";
        
            if (Res.second == -1)
                cout << "at key domino " << Res.first << ".\n";
            else 
                cout << "between key dominoes " << Res.first << " and " << Res.second << ".\n";
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    int tc = 1;
    while (cin >> n >> m, n || m) {
        Graph g(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g.Edge(u-1, v-1, w);
        }
        cout << "System #" << tc++ << endl;
        g.sol();
        cout << endl;
    }
	return 0;
}
