#include <iostream>
#include <sstream>
using namespace std;

struct Set{
    int rank;
    int parent;
    Set() {
        rank = 1;
    }
};

typedef struct Set set;

int Parent(set x[], int a) {
    if (x[a].parent != a)
        x[a].parent = Parent(x, x[a].parent);
    return x[a].parent;
}

void Union(set x[], int a, int b) {
    int pA = Parent(x, a), 
        pB = Parent(x, b);
    if (x[pA].rank > x[pB].rank)
        x[pB].parent = pA;
    else {
        x[pA].parent = pB;
        if (x[pA].rank == x[pB].rank)
            x[pB].rank++;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	string discard;
	getline(cin, discard);
	getline(cin, discard);
	
	string line;
	char query;
	int a, b;
	int successes, failures;
	while (t--) {
	    int n; cin >> n;
	    getline(cin, discard);
	    
	    set x[n+1];
	    for (int i = 1; i <= n; i++)
	        x[i].parent = i;
	    successes = failures = 0;
	    
	    while(getline(cin, line)) {
	        if (line == "") break;
	        stringstream ss(line);
	        ss >> query >> a >> b;
	        
          if (query == 'c') 
	            Union(x, a, b); 
	  
	        else if (query == 'q') {
	            int pA = Parent(x, a), 
                    pB = Parent(x, b);
                if (pA == pB) successes++;
                else failures++;
	        }
	    }
	    cout << successes << "," << failures << endl;
	    if (t) cout << endl;
	}
	return 0;
}
