#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V; 
    vector <int> *adj, indeg;
    
    public:
        Graph() {}
        Graph(int n, int m) : V(n*m), indeg(V, 0) {
            adj = new vector <int> [V];
        }
        void Edge(int u, int v) {
            adj[u].push_back(v);
            indeg[v]++;
        }
        void sol(vector <vector <int>> &mat) {
            int r = mat.size(), c = mat[0].size();
            queue <int> utl;
            for (int i = 0; i < V; i++)
                if (indeg[i] == 0)
                    utl.push(i);
                    
            while (!utl.empty()) {
                int u = utl.front();
                utl.pop();
                for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
                    int v = *i;
                    indeg[v]--; mat[v/c][v%c] += mat[u/c][u%c];
                    if (indeg[v] == 0)
                        utl.push(v);
                }
            }
        }
        ~Graph() {
            delete[] adj;
        }
};

unordered_map <string, int> col;

int toNum(string &digits) {
    int i = 0, neg = 1;
    if (digits[0] == '-') neg = -1, i++;
    
    int num = 0;
    for (; i < digits.size(); i++)
        num = num*10 + (digits[i] - '0');
    return num*neg;
}

pii parse(string &box) {
    string letters = "";
    int num = 0;
    for (char e : box) {
        if (e >= '0' && e <= '9')
            num = num*10 + (e - '0');
        else letters = letters + e;
    }
    
    int r = num - 1;
    int c = col[letters];
    return pii(r, c);
}

void init() {
    string utl = "A"; int k = 0;
    while (true) {
        col[utl] = k++;
        if (utl == "ZZZ") break;
        
        int e = 0;
        if (utl[utl.size() - 1] == 'Z') 
            utl[utl.size() - 1] = 'A', e = 1;
        else utl[utl.size() - 1]++;
        
        for (int i = utl.size() - 2; i >= 0; i--) {
            if (e == 1 && utl[i] != 'Z')
                utl[i]++, e = 0;
            if (e == 1) 
                utl[i] = 'A';
        }
        if (e == 1)
            utl = 'A' + utl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	init();
	int t; cin >> t;
	while (t--) {
	int r, c; cin >> c >> r;
	
	Graph gr(r, c);
	vector <vector <int>> mat(r, vector <int>(c, 0));
	
	string element;
	for (int i = 0; i < r; i++) 
	    for (int j = 0; j < c; j++) {
	        cin >> element;
	        if (element[0] == '=') {
	            string k = ""; pii tmp;
	            for (int g = 1; g < element.size(); g++) {
	                if (element[g] != '+') 
	                    k += element[g];
	                else {
	                    tmp = parse(k); k = "";
	                    gr.Edge(tmp.first*c + tmp.second, i*c + j);
	                }
	            }
	            tmp = parse(k);
	            gr.Edge(tmp.first*c + tmp.second, i*c + j);
	        }
	        else mat[i][j] = toNum(element);
	    }   

	gr.sol(mat);
	for (int i = 0; i < r; i++) {
	    for (int j = 0; j < c; j++) {
	        if (j != 0) cout << " ";
	        cout << mat[i][j];
	    }
	    cout << endl;
	}
	}
	return 0;
}
