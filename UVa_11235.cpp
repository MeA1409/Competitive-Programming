#include <iostream>
#include <vector>
#include <map>
using namespace std;

int max(int a, int b) {
    return (a > b)? a : b;
}

int Tree[1000000];

void Prepare() {
    for (int i = 0; i < 1000000; i++)
        Tree[i] = -1;
}

int buildTree(int index, int L, int R, const vector <int> &fTable) {
    if (L == R) 
        return Tree[index] = fTable[L];
    
    int M = L + (R-L)/2;
    Tree[index] = max(buildTree(index*2, L, M, fTable), 
                      buildTree(index*2+1, M+1, R, fTable));
    return Tree[index];
}

int RMQ(int index, int L, int R, int l, int r) {
    if (R < l || r < L)
        return -1;
        
    if (l <= L && R <= r)
        return Tree[index];
    
    int M = L + (R-L)/2;
    return max(RMQ(index*2, L, M, l, r), RMQ(index*2+1, M+1, R, l, r));
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, q; 
	while (cin >> n, n > 0) {
	    cin >> q;
	    Prepare();
	    vector <int> array(n), fTable(n); 
	    for (int i = 0; i < n; i++) 
	        cin >> array[i];
      map<int, int> leftMost,
                      rightMost;
                      
      for (int i = 0; i < n; ) {
	        int j = 0;
	        for (int k = i; k < n && array[k] == array[i]; k++) j++;
	        
	        leftMost[array[i]] = i; rightMost[array[i]] = i + j - 1;
	        for (int k = 0; k < j; k++) 
	            fTable[i++] = j;
	    }
	    buildTree(1, 0, n-1, fTable);
	    
	    int l, r; 
	    int answer = -1;
	    while (q--) {
          // inputting bounds
	        cin >> l >> r;
	        l--, r--;
	         
	        if (array[l] == array[r]) 
	            answer = r - l + 1;
              
	        // leftMost's and rightMost's all values are present within bounds
          else if ((l == 0 || array[l] != array[l-1]) && (r == n - 1 || array[r] != array[r+1]))
	            answer = RMQ(1, 0, n-1, l, r);
              
	        // rightMost's all values are present in- and also outside the bounds 
	        else if (array[l] == array[l-1] && (r == n - 1 || array[r] != array[r+1]))
	            answer = max(rightMost[array[l]] - l + 1, 
	                    RMQ(1, 0, n-1, rightMost[array[l]]+1, r));
                      
	        // leftMost's all values are present in- and also outside the bounds    
	        else if ((l == 0 || array[l] != array[l-1]) && array[r] == array[r+1])
	            answer = max(r - leftMost[array[r]] + 1, 
	                    RMQ(1, 0, n-1, l, leftMost[array[r]]-1));
                      
	        // leftMost's and rightMost's all values are present outside the bounds             
	        else {
	            answer = max(r - leftMost[array[r]] + 1, rightMost[array[l]] - l + 1);
	            answer = max(answer, RMQ(1, 0, n-1, rightMost[array[l]]+1, leftMost[array[r]]-1));
	        }
	        cout << answer << endl;
	    }
	    
	}
	return 0;
}
