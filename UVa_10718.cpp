#include <iostream>
using namespace std;

typedef unsigned int uint;

int main() {
    ios_base::sync_with_stdio(0);
    uint n, l, u;
    while (cin >> n >> l >> u) {
        uint ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                if ((ans | ((1 << i) - 1)) < l)
                    ans |= (1 << i);
            }
            else {
                if ((ans | (1 << i)) <= u) 
                    ans |= (1 << i);
            }
        }
        cout << ans << endl;
    }
	return 0;
}
