#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n; 
	while (cin >> n, n > 0) {
	    vector <int> parent(n + 1, -1);
	    vector <int> balls(n + 1);
	    vector <int> outDegree(n + 1, 0);
	    
	    for (int i = 1; i <= n; i++) {
	        int v;
	        cin >> v;
	        cin >> balls[v] >> outDegree[v];
	        
	        for (int k = 0; k < outDegree[v]; k++) {
	            int u; cin >> u;
	            parent[u] = v;
	        }
	    }
	    
	    queue <int> Util;
	    for (int i = 1; i <= n; i++)
	        if (outDegree[i] == 0)
	            Util.push(i);
	    
	    int answ = 0;
	    
	    while (!Util.empty()) {
	        int v = Util.front(); 
	        Util.pop();
	        if (parent[v] != -1) {
	            balls[parent[v]] += balls[v] - 1;
	            outDegree[parent[v]]--;
	            if (outDegree[parent[v]] == 0) 
	                Util.push(parent[v]);
	            answ += abs(balls[v] - 1);
	        }
	    }
	    cout << answ << endl;
	}
	return 0;
}
