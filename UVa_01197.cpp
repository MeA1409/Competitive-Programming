#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list <int> *adj;
    public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int a, int b) {
        if (a >= V || b >= V) return;
        adj[a].push_back(b);
    }
    void dfs(int visited[], int x, int &cnt) {
        visited[x] = 1; cnt++;
        list<int>::iterator i;
        for (i = adj[x].begin(); i != adj[x].end(); i++) {
            if (!visited[*i])
                dfs(visited, *i, cnt);
        }
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	while (cin >> n >> m, n || m) {
	    Graph graph(n);
	    int groupSize, 
	        groupyA, groupyB, groupyC;
	    for (int i = 0; i < m; i++) {
	        cin >> groupSize;
	        if (groupSize > 0) 
	            cin >> groupyA;
	        groupyB = groupyA;
	        for (int j = 1; j < groupSize; j++) {
	            cin >> groupyC;
	            graph.addEdge(groupyB, groupyC);
	            groupyB = groupyC;
	        }
	        graph.addEdge(groupyB, groupyA);
	    }
	    
	    int cnt = 0,
	        visited[n] = {0};
	    graph.dfs(visited, 0, cnt);
	    cout << cnt << endl;
	}
	return 0;
}
