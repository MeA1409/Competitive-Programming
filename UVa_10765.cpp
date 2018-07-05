#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector <int> vi;
int cnt;

struct Pair{
	int first, second;
	Pair() : first(-1), second(-1) {}
	Pair(int ff, int ss) : first(ff), second(ss) {}
	bool operator <(Pair &other) {
		return first > other.first || 
		     (first == other.first && second < other.second); 
	}
};

void art(int u, vector <vi> &adj, vi &num, vi &low, vi &p, vi &pid) {
	num[u] = low[u] = cnt++;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (num[v] == -1) {
			p[v] = u;
			art(v, adj, num, low, p, pid);
			
			if (num[u] <= low[v]) 
				pid[u]++;
			
			if (low[u] > low[v])
				low[u] = low[v];
		}
		else if (v != p[u])
			if (low[u] > num[v])
				low[u] = num[v];
	}
}

int recheck(int root, vector <vi> &adj) {
	int n = adj.size();
	int cc = 0; vi vis(n, 0);
	for (int i = 0; i < n; i++) {
		if (i != root && !vis[i]) {
			vi queue; int j = 0;
			queue.push_back(i);
			while (j != queue.size()) {
				int x = queue[j];
				for (int k = 0; k < adj[x].size(); k++) {
					int v = adj[x][k];
					if ( v != root && !vis[v]) {
						vis[v] = 1;
						queue.push_back(v);
					}
				}
				j++;
			}
			cc++;
		}
	}
	return cc;
}

int main() {
	int n, m;
	while (cin >> n >> m, n || m) {
		int u, v;
		vector <vi> adj(n);
		while (cin >> u >> v, u != -1 && v != -1) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cnt = 0;
		vi num(n, -1), low(n), p(n);
		vi pid(n, 1);
		p[0] = 0; 
		
		for (int i = 0; i < n; i++) {
			if (num[i] == -1) {
				art(i, adj, num, low, p, pid);
				pid[i] = recheck(i, adj);
			}
		}
		
		vector <Pair> ret(n);
		for (int i = 0; i < n; i++)
			ret[i] = Pair(pid[i], i);
      
		sort(ret.begin(), ret.end());
		
    for (int i = 0; i < m; i++)
			cout << ret[i].second << " " << ret[i].first << endl;
		cout << endl;
	}
	return 0;
}
