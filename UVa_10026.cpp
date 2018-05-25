#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct problem{
    int i;
    int l, w;
    problem() {}
    problem(int i, int l, int w) {
        this->i = i;
        this->l = l;
        this->w = w;
    }
    bool operator < (struct problem &other) {
        if (l*other.w != other.l*w)
            return l*other.w < other.l*w;
        return i < other.i;
    }
} prob;

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        
        vector <prob> sol;
        int l, w;
        for (int i = 0; i < n; i++) {
            cin >> l >> w;
            sol.push_back(prob(i+1, l, w));
        }
        sort(sol.begin(), sol.end());
        cout << sol[0].i;
        for (int i = 1; i < n; i++)
            cout << " " << sol[i].i;
        cout << endl;
        if (t) cout << endl;
    }
	return 0;
}
