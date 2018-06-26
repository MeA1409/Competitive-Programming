#include <iostream>
#include <map>
#include <string>
using namespace std;

// barely

int sol(map <string, int> &mem, string k) {
    if (k.size() == 0 || mem[k] == 1) return 1;
    if (k.size() == 1 || mem[k] == -1) return 0;
    if (k.size() == 2 && (k[0] + k[1] - 2*'a' == 1))
        return 0;
        
    //cout << k << endl;
    
    int an = 0;
    int s = -1, l = 0;
    char prev = ' ';
    for (int i = 0; i < k.size(); i++) {
        if (k[i] == prev)
            l++;
        else {
            if (l > 1)
                an |= sol(mem, k.substr(0, s) + k.substr(s + l, k.size()));
            prev = k[i];
            s = i, l = 1;
        }
    }
    if (l > 1)
        an |= sol(mem, k.substr(0, s) + k.substr(s + l, k.size()));
    
    if (an == 0) mem[k] = -1;
    else         mem[k] =  1;
    
    return an;
}

int main() {
	int t; cin >> t;
	while (t--) {
	    string k; cin >> k;
	    map <string, int> mem;
	    cout << sol(mem, k) << endl;
	}
	return 0;
}
