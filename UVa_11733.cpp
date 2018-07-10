#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef pair<int, int> pii;

class DisjointSet{
    public:
    int parent, ind;
    int rank;
    DisjointSet() { rank = parent = ind = -1; }
    DisjointSet(int p, int r) : parent(p), rank(r), ind(p) {}
};

int Parent(int ind, DisjointSet Ss[]) {
    if (ind != Ss[ind].parent)
        Ss[ind].parent = Parent(Ss[ind].parent, Ss);
    return Ss[ind].parent;
}
    
void Onion(DisjointSet &one, DisjointSet &other) {
    if (one.rank < other.rank) 
        one.parent = other.parent;
    else {
        if (one.rank == other.rank)
            one.rank++;
        other.parent = one.parent;
    }
}

class Graph {
    vector <pair<int, pii>> adj;
    public:
        Graph() {}
        void edge(int u, int v, int w) {
            adj.push_back(make_pair(w, pii(u, v)));
        }
        pii solve(int N, int A) {
            DisjointSet Ss[N+1];
            for (int i = 1; i <= N; i++) 
                Ss[i] = DisjointSet(i, 1);
            
            long an = 0; int airports = 0;
            int CC = N;
            
            sort(adj.begin(), adj.end());
            for (int i = 0; i < adj.size(); i++) {
                auto utl = adj[i];
                int u = utl.second.first,
                    v = utl.second.second;
                int pu = Parent(u, Ss),
                    pv = Parent(v, Ss);
                if (pu != pv) {
                    CC--; 
                    if (utl.first >= A)
                         an += A, airports++;
                    else an += utl.first;
                    Onion(Ss[pu], Ss[pv]);
                }
            }
            airports += CC; an += A*CC;
            return pii(an, airports);
        }
};

int main() {
    ios_base::sync_with_stdio(0);
	int t; cin >> t;
	for (int s = 0; s < t; s++) {
	    int N, M, A; cin >> N >> M >> A;
	    Graph g;
	    for (int i = 0; i < M; i++) {
	        int u, v, w; cin >> u >> v >> w;
	        g.edge(u, v, w);
	    }
	    pii an = g.solve(N, A);
	    cout << "Case #" << s+1 << ": ";
	    cout << an.first << " " << an.second << endl;
	}
	return 0;
}
