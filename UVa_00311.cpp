#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int box[7];
	while (cin >> box[1] >> box[2] >> box[3] >> box[4] >> box[5] >> box[6], 
	        (box[1] || box[2] || box[3] || box[4] || box[5] || box[6])) {
	    
	    int ans = box[6];
	    
	    ans += box[5];
	    box[1] -= box[5]*11;
	    
	    ans += box[4];
	    box[2] -= box[4]*5;
	    
	    ans += (box[3] + 3)/4;
	    switch(box[3] % 4) {
	        case 1:
	            box[2] -= 5;
	            box[1] -= 7;
	            break;
	        case 2:
	            box[2] -= 3;
	            box[1] -= 6;
	            break;
	        case 3:
	            box[2] -= 1;
	            box[1] -= 5;
	            break;
	        case 0: break;
	    }
	    
	    if (box[2] > 0) {
	        ans += (box[2] + 8) / 9;
	        box[2] -= 9*((box[2] + 8)/9);
	    }
	    
	    if (box[2] < 0)
	        box[1] -= (-box[2])*4;
	    if (box[1] > 0)
	        ans += (box[1] + 35) / 36;
	    cout << ans << endl;
	}
	return 0;
}
