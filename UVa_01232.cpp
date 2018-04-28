//Diusrex's logic

#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b)? a : b;
}

int min(int a, int b) {
    return (a < b)? a : b;
}

struct Node {
    int maxHeight, minHeight;
    bool onHold;
};

Node skyline[1000001];

int Update(int index, int L, int R, int l, int r, int height) {
    if (L > R || r < L || R < l) return 0;
    
    if (L == R) {
        if (height >= skyline[index].maxHeight) {
            skyline[index].minHeight = skyline[index].maxHeight = height;
            return 1;
        }
        return 0;
    }
    
    if (skyline[index].onHold) {
        skyline[index*2].minHeight = skyline[index*2].maxHeight = skyline[index].maxHeight;
        skyline[index*2].onHold = true;
        
        skyline[index*2+1].minHeight = skyline[index*2+1].maxHeight = skyline[index].maxHeight;
        skyline[index*2+1].onHold = true;
        
        skyline[index].onHold = false;
    }
    
    int M = L + (R-L)/2;
    if (l <= L && R <= r) {
        if (height >= skyline[index].maxHeight) {
            skyline[index].minHeight = skyline[index].maxHeight = height;
            skyline[index].onHold = true;
            return R - L + 1;
        }
        else if (height >= skyline[index].minHeight) {
            int spaces = 
                Update(index*2,     L,     M, l, r, height) + 
                Update(index*2 + 1, M + 1, R, l, r, height);
            
            skyline[index].minHeight = min(skyline[index*2].minHeight, 
                                            skyline[index*2+1].minHeight);
            skyline[index].maxHeight = max(skyline[index*2].maxHeight, 
                                            skyline[index*2+1].maxHeight);
            return spaces;
        }
        return 0;
    }
        
    int spaces = 
        Update(index*2,     L,     M, l, r, height) + 
        Update(index*2 + 1, M + 1, R, l, r, height);
    
    skyline[index].minHeight = min(skyline[index*2].minHeight, 
                                            skyline[index*2+1].minHeight);
    skyline[index].maxHeight = max(skyline[index*2].maxHeight, 
                                            skyline[index*2+1].maxHeight);

    return spaces;    
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    
	    for (int i = 0; i < 1000001; i++) {
	        skyline[i].minHeight = skyline[i].maxHeight = 0;
	        skyline[i].onHold = false;
	    }
	    int n; cin >> n;
	    int answer = 0;
	    
	    while (n--) {
	        int l, r, h;
	        cin >> l >> r >> h;
	        r--;
	        answer += Update(1, 1, 100000, l, r, h); 
	    }
	    cout << answer << endl;
	}
	cin >> t;
	return 0;
}
