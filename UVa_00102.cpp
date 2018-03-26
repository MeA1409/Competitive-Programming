#include <iostream>
#include <algorithm>

using namespace std;

string comb[] = {"BGC", "BCG", "GBC", "GCB", "CBG", "CGB"};

int main() {
    ios_base::sync_with_stdio(0);
	int b[3], g[3], c[3];
	int sB, sG, sC;
	
	while (cin >> b[0] >> b[1] >> b[2] 
	           >> g[0] >> g[1] >> g[2] 
	           >> c[0] >> c[1] >> c[2]) 
	{
	    sB = sG = sC = 0;
	    for (int i = 0; i < 3; i++) {
	        sB += b[i];
	        sG += g[i];
	        sC += c[i];
	    }
	        
	    int arr[] = {0, 1, 2};
	    int min = (int)2e9, idx = 0, cost;
	    string res = "";
	    
	    do {
	        cost = sB - b[arr[0]] + sG - g[arr[1]] + sC - c[arr[2]];
	        if (cost < min || (cost == min && comb[idx] < res)) {
	            min = cost; 
	            res = comb[idx];
	        }
	        idx++;
	    }
	    while (next_permutation(arr, arr+3));
	    
	    cout << res << " " << min << endl;
	}
	return 0;
}
