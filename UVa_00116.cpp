#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> vi;

int min(int a, int b) {
    return a < b? a : b;
}

int max(int a, int b) {
    return a > b? a : b;
}


int main() {
	ios_base::sync_with_stdio(0);
	int r, c;
	while (cin >> r >> c) {
	    vector <vi> mat(r, vi(c));
	    for (int i = 0; i < r; i++)
	        for (int j = 0; j < c; j++)
	            cin >> mat[i][j];
	            
	    vector <vi> val(r, vi(c));
	    vector <vi> sol(r, vi(c));
	    
	    for (int i = 0; i < r; i++)
	        val[i][c-1] = mat[i][c-1];
	    
	    for (int j = c-2; j >= 0; j--) {
	        for (int i = 0; i < r; i++) {
	            int up = (i - 1 + r)%r;
	            int through = i;
	            int down = (i + 1)%r;
	            
	            int top = min(up, min(through, down));
	            int bot = max(up, max(through, down));
	            int mid = up + down + through - top - bot;
	            
	            val[i][j] = min(val[top][j+1], min(val[bot][j+1], val[mid][j+1]));
	            if (val[i][j] == val[top][j+1])
	                sol[i][j] = top;
	            else if (val[i][j] == val[mid][j+1])
	                sol[i][j] = mid;
	            else //val[i][j] == val[bot][j+1]
	                sol[i][j] = bot;
	            val[i][j] += mat[i][j];
	        }
	    }
	    int an = (int) 1e9;
	    for (int i = 0; i < r; i++)
	        an = min(val[i][0], an);
	    
	    int k = 0;
	    for (; k < r; k++)
	        if (an == val[k][0])
	            break;
	            
	    cout << k+1;
	    for (int i = 1; i < c; i++) {
	        cout << " " << sol[k][i-1]+1;
	        k = sol[k][i-1];
	    }
	    cout << endl;
	    cout << an << endl;
	}
	return 0;
}
