#include <iostream>
using namespace std;

const int N = 4200000;

int tree[N];
int lazy[N];
enum {NON = 0, ZERO, ONE, SWAP};

void BuildTree(int index, int L, int R, int ss[]) {
    tree[index] = lazy[index] = 0;

    if (L == R) {
        tree[index] = ss[L];
        return;
    }

    int M  = L + (R-L)/2;
    BuildTree(index*2, L, M, ss);
    BuildTree(index*2+1, M+1, R, ss);

    tree[index] = tree[index*2] + tree[index*2 + 1];
}

int flip(int index) {
    if (lazy[index] == ZERO) return ONE;
    if (lazy[index] == ONE) return ZERO;
    if (lazy[index] == SWAP) return NON;
    return SWAP;
}

void lazyUpdate(int index, int L, int R) {
    if (lazy[index] != NON) {
        if (lazy[index] == ZERO) {
            tree[index] = R - L + 1;
            if (L != R) {
                lazy[index*2] = ZERO;
                lazy[index*2+1] = ZERO;
            }
        }
        else if (lazy[index] == ONE) {
            tree[index] = 0;
            if (L != R) {
                lazy[index*2] = ONE;
                lazy[index*2+1] = ONE;
            }
        }
        else if (lazy[index] == SWAP) {
            tree[index] = R - L + 1 - tree[index];
            if (L != R) {
                lazy[index*2] = flip(index*2);
                lazy[index*2 + 1] = flip(index*2 + 1);
            }
        }
    }
    lazy[index] = NON;
}

void Update(int index, int L, int R, int a, int b, int type) {
    if (a > R || b < L) return;
    
    lazyUpdate(index, L, R);
    
    if (a <= L && R <= b) {
        if (type == ZERO) {
            tree[index] = (R - L + 1);
            if (L != R) {
                lazy[index*2] = ZERO;
                lazy[index*2+1] = ZERO;
            }
        }
        else if (type == ONE) {
            tree[index] = 0;
            if (L != R) {
                lazy[index*2] = ONE;
                lazy[index*2+1] = ONE;
            }
        }
        else if (type == SWAP) {
            tree[index] = (R - L + 1) - tree[index];
            if (L != R) {
                lazy[index*2] = flip(index*2);
                lazy[index*2 + 1] = flip(index*2 + 1);
            }
        }
        return;
    }

    int M = L + (R-L)/2;
    Update(index*2, L, M, a, b, type);
    Update(index*2 + 1, M+1, R, a, b, type);

    tree[index] = tree[index*2] + tree[index*2 + 1];
}

int Query(int index, int L, int R, int a, int b) {
    lazyUpdate(index, L, R);
    if (a > R || b < L) return 0;

    if (a <= L && R <= b)
        return tree[index];

    int M = L + (R-L)/2;

    int left = Query(index*2, L, M, a, b);
    int right = Query(index*2 + 1, M+1, R, a, b);

    return left + right;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	int s = 1;
	while (t--) {
	    int sets; cin >> sets;
	    
	    int size = N/4;
	    int ss[size];
	    int i = 0;
        while (sets--) {
            int T; cin >> T;
            string pat; cin >> pat;
            while (T--) {
                for (int j = 0; j < pat.size(); j++)
                    ss[i++] = (pat[j] - '0');
            }
        }

        int n = i - 1;
        BuildTree(1, 0, n-1, ss);
        
        int q; cin >> q;
        int counter = 1;
        
        cout << "Case " << s++ << ":\n";
        while (q--) {
            char cmd; cin >> cmd;
            int a, b; cin >> a >> b;

            if (cmd == 'F')
                Update(1, 0, n-1, a, b, ZERO);

            else if (cmd == 'E')
                Update(1, 0, n-1, a, b, ONE);

            else if (cmd == 'I')
                Update(1, 0, n-1, a, b, SWAP);

            else {
                cout << "Q" << counter++ << ": " << Query(1, 0, n-1, a, b) << endl;
            }
        }
	}
	return 0;
}
