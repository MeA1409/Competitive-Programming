#include <bits/stdc++.h>
using namespace std;

long mem[2][100][100]; 

long func(int p, int rem, int lockedUp) {
    long &ret = mem[lockedUp][p][rem];
    if (ret != -1)
        return ret;
    
    if (p < rem) return 0;
    if (rem == 0) {
        if (p > 0) {
            if (lockedUp == 1)
                return ret = func(p - 1, rem, 0);
            else 
                return ret = func(p - 1, rem, 1) + func(p - 1, rem, 0);
        }
        return 1;
    }

    long an = 0;
    if (lockedUp == 1)
        an = func(p - 1, rem - 1, 1) + func(p - 1, rem, 0);
    else 
        an = func(p - 1, rem, 1) + func(p - 1, rem, 0);
    return ret = an;
}

int main() {
    int p, rem;
    while (cin >> p >> rem, p >= 0 && rem >= 0) {
        memset(mem, -1, sizeof(mem));
	      cout << func(p, rem, 1) << endl;
    }  
	  return 0;
}
