#include <iostream>
using namespace std;

int sol(long &num) {
    long s1 = num + 1, 
         s2 = num - 1;
    int c1 = 0, c2 = 0;
    
    if (num <= 3) {
        c1 = num, num = 0;
        return c1;
    }
    
    while (s1 > 0 && s1 % 2 == 0) 
        s1 /= 2, c1++;
    while (s2 > 0 && s2 % 2 == 0) 
        s2 /= 2, c2++;
    
    if (c1 >= c2) {
        num = s1;
        return c1 + 1;
    }
    
    num = s2;
    return c2 + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	long n; 
	while (cin >> n) {
	    int cnt = 0;
	    while (n != 0) {
	        if (n%2 == 0) 
	            cnt++, n/=2;
	        else cnt += sol(n);
	    }
	    cout << cnt << endl;
	}
	return 0;
}
