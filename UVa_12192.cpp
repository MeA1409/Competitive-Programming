#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    int n, m; 
    while (cin >> n >> m, n > 0 && m > 0) {
        vector < vector <int> > mat(n, vector <int>(m));
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                cin >> mat[i][j];

        int t; cin >> t;
        
        while (t--) {
            int l, r; cin >> l >> r;
            int MAX = 0;
            int col, row;
            for (int i = n - 1; i >= 0; i--) {
                col = upper_bound(mat[i].begin(), mat[i].end(), r) - mat[i].begin();
                
                // check if there's a larger rectangle
                col = col - 1 - MAX; row = i - MAX;
                
                if (col < 0) continue;
                if (row < 0) break;
        
                while (col >= 0 && row >= 0 && mat[row][col] >= l)
                    col--, row--, MAX++;
            }
            cout << MAX << endl;
        }
        cout << "-\n";
    }
	return 0;
}
