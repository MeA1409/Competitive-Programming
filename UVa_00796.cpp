#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

typedef vector <int> vi;
typedef pair<int, int> pii;
int cnt;

void sol(vector <vi> &adj, int u, vector <pii> &an, vi &low, vi &num, vi &p) {
	low[u] = num[u] = cnt++;
	for (int j = 0; j < adj[u].size(); j++) {
		int v = adj[u][j];
		if (num[v] == -1) {
			p[v] = u;
			sol(adj, v, an, low, num, p);
			if (low[v] > num[u]) {
				if (u > v)
					an.push_back(pii(v, u));
				else	an.push_back(pii(u, v));
			}

			if (low[u] > low[v])
				low[u] = low[v];
		}
		else if (p[u] != v) 
			if (low[u] > num[v])
				low[u] = num[v];
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector <vi> adj(n);
		for (int i = 0; i < n; i++) {
			int u; cin >> u;
			string smt; cin >> smt;
			stringstream ss(smt);
			char _; int s;
			ss >> _ >> s >> _;
			for (int j = 0; j < s; j++) {
				int v; cin >> v;
				adj[u].push_back(v);
			}
		}
		cnt = 0;
		vi num(n, -1), low(n);
		vi p(n, 0);
		vector <pii> an;
		for (int i = 0; i < n; i++) {
			if (num[i] == -1)
				sol(adj, i, an, low, num, p);
		}
		cout << an.size() << " critical links\n";
		sort(an.begin(), an.end());
		for (int i = 0; i < an.size(); i++) 
			cout << an[i].first << " - " << an[i].second << endl;
		cout << endl;
	}
	return 0;
}
