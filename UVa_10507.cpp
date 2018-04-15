#include <iostream>
#include <vector>
using namespace std;

int getNum(char &e) {
    return e - 'A';
}

int main() {
	ios_base::sync_with_stdio(0);
	int n; 
	
	while (cin >> n) {
    	int m; cin >> m;
	    string woken; cin >> woken;
	    vector <int> brainUp, 
	                 awake(26, 0),
	                 connections(26, 0);
        vector <vector <int>> connected(26, vector<int>(26));
        
	    int section;
	    for (char &e:woken) {
	        section = getNum(e);
	        brainUp.push_back(section);
	    }
	
	    string linkage;
	    int h, t;
    	for (int i = 0; i < m; i++) {
	        cin >> linkage;
	        h = getNum(linkage[0]);
	        t = getNum(linkage[1]);
	        connected[h][t] = connected[t][h] = 1;
	    }
	
	    int years = 0;
	    while (!brainUp.empty()) {
	        while (!brainUp.empty()) {
                section = brainUp.back();
                brainUp.pop_back();
                for (int i = 0; i < 26; i++)
                    if (connected[section][i] && !awake[i])
                        connections[i]++;
                n--;    
                awake[section] = 1;
	        }
	        if (n == 0) break;
	        years++;
	        for (int i = 0; i < 26; i++)
	             if (connections[i] >= 3 && !awake[i])
	                 brainUp.push_back(i);
	    }
	
	    if (n > 0) cout << "THIS BRAIN NEVER WAKES UP\n";
	    else cout << "WAKE UP IN, " << years << ", YEARS\n";
	}
	return 0;
}
