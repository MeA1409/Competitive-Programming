#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	for (int s = 1; s <= t; s++) {
	    cout << "Case #" << s << ": ";
	    int n, m;
	    long k; cin >> n >> m >> k;
	    
	    vector <vector <long>> land(n, vector <long> (m));
	    for (int i = 0; i < n; i++)
	        for (int j = 0; j < m; j++)
	            cin >> land[i][j];
	    long an = (long) 1e17;
	    int mal = 0;
	    for (int i = 0; i < n; i++) {
	        vector <long> sum(m, 0);
	        for (int ie = i; ie < n; ie++) {
	            long util = 0;
	            for (int je = 0, j = 0; je < m; je++) {
	                sum[je] += land[ie][je];
	                util += sum[je];
	                while (util > k) util -= sum[j++];
	                if ((je - j + 1)*(ie - i + 1) > mal) 
	                    mal = (je - j + 1)*(ie - i + 1), an = util;
	                else if ((je - j + 1)*(ie - i + 1) == mal && util < an)
	                    an = util;
	    }}}
	    cout << mal << " " << an << endl;
	}
	return 0;
}
