#include <iostream>
#include <vector>
#include <list>
using namespace std;

class graph{
    list <int> *adj;
    int k;
    public:
        graph() {}
        graph(int _k) : k(_k) {
            adj = new list <int> [26];
        }
        void edge(int u, int v) {
            adj[u].push_back(v);
        }        
        void modDFS(int u, int v) {
            vector <int> marked(26, 0);
            int s = 1;
            while (true) {
                int fin = 1;
                for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
                    if (!marked[*i] && *i != v) {
                        if (s == k) {
                            cout << (char) (u + 'A') << " ";
                            marked[u] = 1, s = 0;
                        }
                        v = u, u = *i, s++;
                        fin = 0;
                        break;
                    }
                }
                if (fin == 1) {
                    cout << "/" << (char) (u + 'A');
                    break;
                }
            }
        }
};

int main() {
	string line; 
	while (cin >> line, line[0] != '#') {
    	char m, t; cin >> m >> t;
    	int k; cin >> k;
	
    	graph G(k);
    	int op = 0; int u, v;
	    for (char l : line) {
	        if (l == ':')
	            op = 1;
	        else if (l == ';')
	            op = 0;
    	    else if (l != '.') {
    	        if (op == 0) 
    	            u = l - 'A';
    	        else {
    	            v = l - 'A';
    	            G.edge(u, v);
	            }
	        }
	    }
	    G.modDFS(m - 'A', t - 'A');
	    cout << endl;
	}
	return 0;
}
