#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	int n, m;
	while (t--) {
	  cin >> n >> m;
		vector <vector <int>> mat(n+1, vector <int>(m+1, 0)),
				      sol(n+1, vector <int>(m+1, 0));

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> mat[i][j];
		
    		for (int i = 1; i <= m; i++)
			if (mat[1][i] >= 5)
				sol[1][i] = mat[1][i];
		
			
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 1; k < j; k++) {
					if (mat[i][k] >= 5 && sol[i-1][j-k]> 0 && 
						  mat[i][k] + sol[i-1][j-k] > sol[i][j]) {
							  sol[i][j] = mat[i][k] + sol[i-1][j-k];
						}
				}
			}
		}
		
		if (sol[n][m] == 0)
			cout << "Peter, you shouldn't have played billiard that much.\n";
		else 
			cout << fixed << setprecision(2) << "Maximal possible average mark - " 
			     << (double)sol[n][m]/n + 1e-9 << ".\n";
	}
	return 0;
}
