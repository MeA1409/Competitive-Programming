#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n; long p;
    while (cin >> n >> p, n || p) {
        long long x = sqrt(p);
        
        // finding ring
        if (!(x*x == p && x%2 == 1)) {
            if (x&1) x++;
            x++;
        }
        
        int i, j;
        
        // setting position to the top right corner of the found ring (1-indexed)
        i = j = x/2 + n/2 + 1;
        
        // avoiding floating-point exception
        if (x != 1) {
            int g = (x*x - p)/(x-1);
            switch(g) {
                case 0:
                    i -= (x*x - p);
                    break;
                case 1: 
                    i -= x - 1;
                    j -= (x*x - p)%(x-1);
                    break;
                case 2:
                    i -= (x - 1) - (x*x - p)%(x-1);
                    j -= x - 1;
                    break;
                case 3: 
                    j -= (x - 1) - (x*x - p)%(x-1);
                    break;
                }
            } 
        cout << "Line = " << i << ", column = " << j << ".\n";
    }
}
