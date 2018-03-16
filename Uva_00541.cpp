#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
	int n, x, y;
	while (cin >> n, n > 0) {
	    int mat[n][n];
	    x = y = -1;
	    
      for (int i = 0; i < n; i++)
	        for (int j = 0; j < n; j++) 
	            cin >> mat[i][j];
	            
	    for (int i = 0; i < n; i++) {
	        int tempX = 0, tempY = 0;
	        for (int j = 0; j < n; j++) {
	            if (mat[i][j] == 1) tempX++;
	            if (mat[j][i] == 1) tempY++;
	        }
	        if (tempX&1) x = i;
	        if (tempY&1) y = i;
	    }
	    
	    if (x == -1 && y == -1) {
	        cout << "OK\n"; continue; }
	        
	    mat[x][y] ^= 1;
	    bool pos = true;
	    
	    for (int i = 0; i < n; i++) {
	        int tempX = 0, tempY = 0;
	        for (int j = 0; j < n; j++) {
	            if (mat[i][j] == 1) tempX++;
	            if (mat[j][i] == 1) tempY++;
	        }
	        if (tempX&1) {
	            pos = false; break; }
	        else if (tempY&1) {
	            pos = false; break; }
	    }
	    
	    if (pos) 
	        cout << "Change bit (" << x+1 << "," << y+1 << ")\n";
	    else cout << "Corrupt\n";
	}
	return 0;
}
