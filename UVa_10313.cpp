#include <iostream>
#include <sstream>
using namespace std;

int min(int a, int b) {
    return a < b? a : b;
}

long memo[301][301];

int main() {
	ios_base::sync_with_stdio(0);
	
	memo[0][0] = 1;
	for (int i = 1; i <= 300; i++) {
	    for (int j = i; j <= 300; j++)
	        for (int k = 1; k <= 300; k++)
	            memo[j][k] += memo[j-i][k-1];
	}

	for (int j = 0; j <= 300; j++)
	    for (int k = 1; k <= 300; k++)
	        memo[j][k] += memo[j][k-1];
	        
	string line;
	while (getline(cin, line)) {
	    stringstream ss(line);
	    int a[3]; int n = 0;
	    while (ss >> a[n]) n++;
	    
        if (n == 1) 
            cout << memo[a[0]][300] << endl;
        else if (n == 2)
            cout << memo[a[0]][min(a[1], 300)] << endl;
        else if (n == 3) {
            long an = memo[a[0]][min(a[2], 300)];
            if (a[1] > 0) an -= memo[a[0]][min(a[1]-1, 300)];
            cout << an << endl;
        }
	}
	return 0;
}
