#include <iostream>

using namespace std;

long power(long x, int y) {
    if(y == 0)  return 1;
    if(y&1)
        return x*power(x*x, y/2);
    else
        return power(x*x, y/2);
}

long sol(int n, int x, int arr[]) {
    long res = 0;
    for (int i = 0; i <= n; i++)
        res += power(x, i)*arr[i];
    return res;
}

int main() {
  ios_base::sync_with_stdio(0);
	int t; cin >> t;
	int d, k, n;
	while (t--) {
            int arr[22];
	    cin >> n;
	    for (int i = 0; i <= n; i++)
	        cin >> arr[i];
	    cin >> d >> k;
	    
            int x = k;
	    long j = 1;
	    while (x > j*d) {
	        x -= j*d;
	        j++;
	    }
	    long res = sol(n, j, arr);
	    cout << res << endl;
	}
	return 0;
}
