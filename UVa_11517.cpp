#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

pii solve(vector <vector <pii>> &mem, vector <int> &ar,
                                            int id, int rem) 
{
    if (rem <= 0) 
        return pii(0, 0);
    if (id >= ar.size())
        return pii(100000000, 100000000);
    
    pii &inMem = mem[id][rem];
    
    if (inMem.first != -1 && inMem.second != -1)
        return inMem;
    
    pii x = solve(mem, ar, id+1, rem);
    pii y = solve(mem, ar, id+1, rem - ar[id]);
    y.second += 1; y.first += ar[id];
    
    if (x.first != y.first) 
        return inMem = (x.first < y.first)? x : y;
    return inMem = (x.second < y.second)? x : y;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int s, n; cin >> s >> n;
	    
	    vector <vector <pii>> mem(n, vector <pii> (s+1, pii(-1, -1)));
	    vector <int> ar(n);
	    for (int i = 0; i < n; i++)
	        cin >> ar[i];
	    
	    pii an = solve(mem, ar, 0, s);
	    cout << an.first << " " << an.second << endl;
	}
	return 0;
}


/*
/////////////////////////////////////////
// iterative solution (quicker overall)
/////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

const int inf = (int) 1e9;

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int s, n; cin >> s >> n;
	    
	    vector <int> memo(20001, inf);
	    vector <int> ar(n);
	    for (int i = 0; i < n; i++)
	        cin >> ar[i];
	    
	    memo[0] = 0;
	    for (int i = 0; i < n; i++) {
	        for (int j = 20000; j >= ar[i]; j--)
	            memo[j] = min(memo[j], 1 + memo[j-ar[i]]);
	    }
	    int amt = inf, coins = inf;
	    for (int j = s; j <= 20000; j++)
	        if (memo[j] != inf) {
	            amt = j;
	            coins = memo[j];
	            break;
	        }
	    cout << amt << " " << coins << endl;
	}
	return 0;
}
*/
