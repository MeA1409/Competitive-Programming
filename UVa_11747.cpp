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
        vi solve(int N) {
            DisjointSet Ss[N];
            for (int i = 0; i < N; i++) 
                Ss[i] = DisjointSet(i, 1);

            vi an;
            sort(adj.begin(), adj.end());
            for (int i = 0; i < adj.size(); i++) {
                auto utl = adj[i];
                int u = utl.second.first,
                    v = utl.second.second;
                int pu = Parent(u, Ss),
                    pv = Parent(v, Ss);
                if (pu != pv) 
                    Onion(Ss[pu], Ss[pv]);
                else an.push_back(utl.first);
            }
            return an;
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    int N, M;
	while (cin >> N >> M, N || M) {
	    Graph g;
	    for (int i = 0; i < M; i++) {
	        int u, v, w; cin >> u >> v >> w;
	        g.edge(u, v, w);
	    }
	    
	    vi an = g.solve(N);
	    if (an.size() == 0)
	        cout << "forest\n";
	    else {
	        cout << an[0];
	        for (int i = 1; i < an.size(); i++)
	            cout << " " << an[i];
	        cout << endl;
	    }
	}
	return 0;
}
