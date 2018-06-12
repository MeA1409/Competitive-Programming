#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Doll {
    int w, h;
    Doll() {}
    Doll(int W, int H) : w(W), h(H) {}
    bool operator < (Doll &a) {
        if (h != a.h) 
            return h > a.h;
        return w < a.w;
    }
} doll;

void sol(vector <doll> &utl) {
    sort(utl.begin(), utl.end());
    
    vector <int> li;
    for (int i = 0; i < utl.size(); i++) {
        int j = upper_bound(li.begin(), li.end(), utl[i].w) - li.begin();
        if (j == li.size()) li.push_back(utl[i].w);
        else                li[j] = utl[i].w;
    }
    cout << li.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <doll> utl(n);
        for (int i = 0; i < n; i++) {
            int w, h; cin >> w >> h;
            utl[i] = doll(w, h);
        }
        sol(utl);
    }
	return 0;
}
