#include <iostream>
using namespace std;

const int inf = (int) 1e8;

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        string line; cin >> line;
        int n = line.size();
        int arr[n][n];
        int i = 0;
        while (i < n) {
            for (int j = 0; j < n; j++)
                arr[i][j] = (line[j] == '0')? -inf : 1;
            i++; if (i >= n) break;
            cin >> line;
        }
        
        int ans = 0;
        int s[n] = {0};
        for (i = 0; i < n; i++) {
            for (int ie = i; ie < n; ie++) {
                int util = 0;
                for (int j = 0; j < n; j++) {
                    if (i == ie) s[j] = 0;
                    s[j] += arr[ie][j], util += s[j];
                    
                    if (util > ans) ans = util;
                    if (util < 0) util = 0;
                }
            }
        }
        cout << ans << endl;
        if (t) 
            cout << endl;
    }
	return 0;
}
