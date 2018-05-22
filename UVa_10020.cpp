#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int m; cin >> m;
	    int l, r;
	    vector <pair<int, int>> sol;
	    while (cin >> l >> r, l || r) {
	        sol.push_back(make_pair(l, r));
	    }
      sort(sol.begin(), sol.end());

      vector <pair<int, int>> segs;
      int i, j;
	    int furthest = 0;
	    int steps = 0;
	    for (i = 0; i < sol.size(); i = j) {
	        if (sol[i].first > furthest) break;
	        
	        for (j = i + 1; j < sol.size(); j++) {
	            if (sol[j].first <= furthest) {
	                if (sol[j].second > sol[i].second) 
	                    i = j;
	            }
	            else break;
	        }
	        
	        segs.push_back(make_pair(sol[i].first, sol[i].second));
	        furthest = sol[i].second;
	        steps++;
	        if (furthest >= m) break;
	     }
	     if (furthest < m) cout << 0 << endl;
	     else {
	        cout << steps << endl;
	        for (int i = 0; i < segs.size(); i++)
	            cout << segs[i].first << " " << segs[i].second << endl;
	     }
	     if (t) cout << endl;
	}
	return 0;
}
