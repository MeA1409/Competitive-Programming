#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair<int, int> pii;
const int inf = (int) 0x3c3c3c3c;
const int N = (int) 1e4+1;
vector <int> cities(N);
vector <pii> adj[N];
int n, m;
int cap;

int cost[N][101];
int sol(int st, int ed) {
    memset(cost, 60, sizeof(cost));
    cost[st][0] = 0;
    priority_queue<pair<int, pii>> Q;
    Q.push(make_pair(-cost[st][0], pii(st, 0)));
    while (!Q.empty()) {
        pair<int, pii> T = Q.top(); Q.pop();
        int u = T.second.first, 
         fuel = T.second.second;
         
        if (-T.first != cost[u][fuel]) continue;
        if (u == ed) 
            return -T.first;
        
        if (fuel < cap) {
            cost[u][fuel+1] = cost[u][fuel] + cities[u];
            Q.push(make_pair(-cost[u][fuel+1], pii(u, fuel+1)));
        }
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].first;
            int d = adj[u][j].second;
            if (fuel >= d) {
                if (cost[v][fuel - d] > cost[u][fuel]) {
                    cost[v][fuel - d] = cost[u][fuel];
                    Q.push(make_pair(-cost[v][fuel - d], pii(v, fuel - d)));
                }
            }
        }
    }
    return inf;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> cities[i];
    while (m--) {
        int u, v; cin >> u >> v;
        int d; cin >> d;
        adj[u].push_back(pii(v, d));
        adj[v].push_back(pii(u, d));
    }
    int q; cin >> q;
    while (q--) {
        cin >> cap;
        int st, ed; cin >> st >> ed;
        int an = sol(st, ed);

        if (an != inf) 
            cout << an << endl;
        else cout << "impossible\n";
    }
}
