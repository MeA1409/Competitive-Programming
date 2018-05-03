#include <iostream>
#include <vector>

using namespace std;

class FenwickTree{
        int n;
        vector <int> FT;
    public:
        void Update(int val, int index) {
                if (val == 0) return;
                
                index++;
                while (index <= n) {
                    FT[index] += val;
                    index += index & (-index);
                }
        }
        
        FenwickTree(const vector <int> &array, int flag) {
            n = array.size();
            FT.assign(n + 1, 0);
            if (flag)
                for (int i = 0; i < n; i++)
                    Update((array[i] < 0), i);
            else 
                for (int i = 0; i < n; i++)
                    Update((array[i] == 0), i);
        }
        
        int CumuSum(int index) {
            int sum = 0;
            while (index > 0) {
                sum += FT[index];
                index -= index & (-index);
            }
            return sum;
        }
        
        int RangeSum(int l, int r) {
            return CumuSum(r) - CumuSum(l-1);
        }
};

int main() {
	ios_base::sync_with_stdio(0);
	int n, q; cin >> n >> q; 
	do {
	    vector <int> array(n);
	    for (int i = 0; i < n; i++)
	        cin >> array[i];
	        
	    FenwickTree negative(array, 1), 
	                zero(array, 0);
	    while (q--) {
	        char cmd; cin >> cmd;
	        if (cmd == 'C') {
	            int x, val;
	            cin >> x >> val;
	            x--;
	            negative.Update((val < 0) - (array[x] < 0), x);
              zero.Update((val == 0) - (array[x] == 0), x);
              array[x] = val;
	        }
	        else {
	            int l, r;
	            cin >> l >> r;;
	            if (zero.RangeSum(l, r))
	                cout << 0;
	            else if (negative.RangeSum(l, r)&1)
	                cout << '-';
	            else cout << '+';
	        }
	    }
	    cout << endl;
	}
	while (cin >> n >> q);
	return 0;
}
