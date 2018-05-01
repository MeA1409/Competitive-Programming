#include <iostream>
using namespace std;

const int N = 200002;

int n;
int tree[N];

int Sum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= i & (-i);
    }
    return sum;
}

void Fenwick(int i, int value) {
    while (i <= n) { 
        tree[i] += value;
        i += i & (-i);
    }
}

void Construct(int array[]) {
    for (int i = 0; i <= 200001; i++)
        tree[i] = 0;
        
    for (int i = 1; i <= n; i++)
        Fenwick(i, array[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
    	int t = 1;
	while (cin >> n, n > 0) {
	    if (t > 1) cout << endl;
	    cout << "Case " << t++ << ":\n";

	    int array[n+1];
	    for (int i = 1; i <= n; i++)
	       cin >> array[i];
	       
	    Construct(array);
	    string query;

	    while (cin >> query) {
	        if (query == "END") break;
	        if (query == "M") {
	            int l, r;
	            cin >> l >> r;
	            cout << Sum(r) - Sum(l-1) << endl;
	        }
	        else {
	            int i, val;
	            cin >> i >> val;
	            Fenwick(i, val - array[i]);
	            array[i] = val;
	        }
	    }
	}
	return 0;
}
