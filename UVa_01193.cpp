#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<double, double> pdd;

int main() {
	ios_base::sync_with_stdio(0);
	int n, r;
	int t = 1;
	while (cin >> n >> r, n || r) {
	    int x, y;
	    int maxY = 0;
	    
	    vector <pdd> sol;
	    for (int i = 0; i < n; i++) {
	        cin >> x >> y;
	        if (maxY < abs(y)) maxY = abs(y);
	        if (maxY <= r) {
	            double itv = sqrt(r*r - y*y);
	            sol.push_back(make_pair(x + itv, x - itv));
	        }
	    }
	    if (maxY > r) {
	        cout << "Case " << t++ << ": -1\n";
	        continue;
	    }
	    
	    sort(sol.begin(), sol.end());
	    
	    int i, j;
	    int answer = 0;
	    for (i = 0; i < n; i = j) {
	        for (j = i + 1; j < n; j++)
	            if (sol[j].second > sol[i].first)
	                break;
	        answer++;
	    }
	    cout << "Case " << t++ << ": " << answer << endl;
	}
	return 0;
}
