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

int bfs(vector <int> adj[], vector <edge> &Edge, pii parent[], int sink) {
    int vis[sink+1] = {0};
    queue<int> Q; Q.push(0);
    vis[0] = 1; parent[0] = pii(-1, -1);
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
    return vis[sink];
}

int Edmonds(vector <int> adj[], vector <edge> &Edge, int sink) {
    pii parent[sink+1];
    int total = 0;
    while (bfs(adj, Edge, parent, sink)) {
        int curflow = inf;
        int v = sink,
            u = parent[v].first;
        while (u != -1) {
            curflow = min(curflow, Edge[parent[v].second].cap);
            v = u, u = parent[v].first;
        }
        v = sink, u = parent[v].first;
        while (u != -1) {
            Edge[parent[v].second].cap -= curflow;
            Edge[Edge[parent[v].second].rev].cap += curflow;
            v = u, u = parent[v].first;
        }
        total += curflow;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; int s = 1;
    while (cin >> n, n > 0) {
        cout << "Case " << s++ << ": ";
        cin >> m;
        int v, a, b; 
        int tot = 0;

        vector <pii> points(n);
        vector <edge> Edge;
        vector <int> nums;
        vector <int> adj[301];

        for (int i = 1; i <= n; i++) {
            cin >> v >> a >> b;      tot += v;
            points[i-1] = pii(a, b);
            add(adj, Edge, 0, i, v);
            nums.push_back(a);
            nums.push_back(b);
        }
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int sink = n + nums.size();
        for (int i = 1; i <= n; i++) {
            int st = lower_bound(nums.begin(), nums.end(), points[i-1].first) - nums.begin();
            for (; nums[st] < points[i-1].second; st++) 
                add(adj, Edge, i, n + st + 1, nums[st+1] - nums[st]);
        }
        for (int st = 0; st < nums.size() - 1; st++) 	
    	    add(adj, Edge, n + st + 1, sink, (nums[st+1] - nums[st])*m);
    
        int an = Edmonds(adj, Edge, sink); 
        if (tot == an) {
            cout << "Yes\n";
            int trace[nums.size() - 1] = {0};
            vector <pii> sol[n];
            for (int st = 0; st < nums.size() - 1; st++) {
                for (int j = 0; j < adj[st + n + 1].size(); j++) {
                    int ind = adj[st + n + 1][j];
                    int v = Edge[ind].v,
                        cap = Edge[ind].cap;
                    if (v <= n && cap > 0) {
                        int l = nums[st] + trace[st],
                            r = l + cap;
                        if (r > nums[st+1]) {
                            int _l = nums[st],
                                _r = nums[st] + r - nums[st+1];
                            if (!sol[v-1].empty() && _l == sol[v-1].back().second)
                                sol[v-1].back().second = _r;
                            else sol[v-1].push_back(pii(_l, _r));
                            
                            trace[st] = _r - nums[st];
                            r = nums[st+1];
                        }
                        else trace[st] = r - nums[st];

                        if (l == r) continue;
                        if (!sol[v-1].empty() && l == sol[v-1].back().second)
                            sol[v-1].back().second = r;
                        else sol[v-1].push_back(pii(l, r));
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                cout << sol[i].size() << " ";
                int f = 1;
                for (int j = 0; j < sol[i].size(); j++) {
                    if (!f) cout << " "; else f = 0;
                    cout << "(" << sol[i][j].first << "," << sol[i][j].second << ")";
                }
                cout << endl;
            }
        }
        else 
            cout << "No\n";
    }
    return 0;
}
