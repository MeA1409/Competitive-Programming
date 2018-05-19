// someone else' clever logic 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct sprinkler{
    double l, r;
    sprinkler () {}
    sprinkler (double a, double b) {
        l = a, r = b;
    }
    bool operator < (const sprinkler &other) {
        return l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    int n, l;
    double w;
    while (cin >> n >> l >> w) {
        w /= 2.0;
        vector <sprinkler> sol;
        
        int p, r;
        double range;
        for (int i = 0; i < n; i++) {
            cin >> p >> r;
            if (r > w) {
                range = sqrt((double) r*r - w*w);
                sol.push_back(sprinkler(p - range, p + range));
            }
        }
        sort(sol.begin(), sol.end());
        
        double furthest = 0.0;
        int answer = 0;
        int i, j;
        for (i = 0; i < sol.size(); i = j) {
            if (sol[i].l > furthest) break;
            for (j = i + 1; j < sol.size() && sol[j].l <= furthest; j++) 
                if (sol[j].r > sol[i].r)
                    i = j;
            furthest = sol[i].r;
            // if you use it, you add it
            answer++;
            if (furthest >= l) break;
        }
        if (furthest >= l) cout << answer << endl;
        else cout << -1 << endl;
    }    
    return 0;
}
