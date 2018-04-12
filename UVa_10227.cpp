#include <iostream>
#include <sstream>
using namespace std;

#define max_people 100
#define max_trees 100

int forest[max_people][max_trees];
int x[max_people], Rank[max_people];
int differences;

int parent(int a) {
    if (x[a] != a)
        x[a] = parent(x[a]);
    return x[a];
}

void Union(int a, int b) {
    int pA = parent(a);
    int pB = parent(b);
    if (pA == pB) return;
    differences--;
    if (Rank[pA] > Rank[pB])
        x[b] = pA;
    else {
        x[a] = pB;
        if (Rank[pA] == Rank[pB])
            Rank[pB]++;
    }
}


int sameOpinion(int a, int b, int t) {
    for (int i = 1; i <= t; i++) 
        if (forest[a][i] != forest[b][i])
            return 0;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	int s; cin >> s;
	string discard;
	getline(cin, discard);
	getline(cin, discard);
	int p, t;
	while (s--) {
	    cin >> p >> t;
	    getline(cin, discard);

	    for (int i = 1; i <= p; i++) {
	        for (int j = 1; j <= t; j++)
	            forest[i][j] = 0;
	        Rank[i] = 1;
	        x[i] = i;
	    }
	    differences = p;
	    
	    string line;
	    int person, tree;
	    while (getline(cin, line)) {
	        if (line == "") break;
	        stringstream ss(line);
	        ss >> person >> tree;
	        forest[person][tree] = 1;
	    }
	    
	    for (int i = 1; i < p; i++) 
	        for (int j = i+1; j <= p; j++) 
	            if (sameOpinion(i, j, t))
	                Union(i, j);
	    cout << differences << endl;
	    if (s) cout << endl;
	}
	return 0;
}
