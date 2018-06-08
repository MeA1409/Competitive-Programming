// morris's got an amazing O(n^5) algorithm

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int a, b, c;
	    cin >> a >> b >> c;
	    long box[a][b][c];
	    long pillarSum[a][b][c];

	    long ans = (long) -1e12;
	    
	    for (int i = 0; i < a; i++) {
	        for (int j = 0; j < b; j++) { 
	            for (int k = 0; k < c; k++) {
	                cin >> box[i][j][k];
	                if (box[i][j][k] > ans) 
	                    ans = box[i][j][k];
	                
	                pillarSum[i][j][k] = box[i][j][k];
	                if (i > 0) 
	                    pillarSum[i][j][k] += pillarSum[i-1][j][k];
	            }
	        }
	    }      
	    
	    for (int i = 0; i < a; i++) 
	    for (int ie = i; ie < a; ie++) {
	        for (int j = 0; j < b; j++) {
	            long miniboxSum[c] = {0};
	        for (int je = j; je < b; je++) {
	            long util = 0;
	            for (int k = 0; k < c; k++) {
	                miniboxSum[k] += pillarSum[ie][je][k];
	                if (i > 0) miniboxSum[k] -= pillarSum[i-1][je][k];
	                    
	                util += miniboxSum[k];
	                if (util > ans) ans = util;
	                if (util < 0) util = 0;
	            }
	        }
	        }
	    }
	    cout << ans << endl;
	    if (t) cout << endl;
	}
	return 0;
}
