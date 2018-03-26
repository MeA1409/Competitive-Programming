#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <unsigned int> sol(10001);

int main() {
    ios_base::sync_with_stdio(0);
    unsigned int num;
    int i = 0;
    
    while (cin >> num)
        sol[i++] = num;
    
    int ans;
    for (int k = 1; k <= i; k++) {
        nth_element(sol.begin(), sol.begin()+k/2, sol.begin()+k);
        ans = sol[k/2];
        if (k%2 == 0) {
            nth_element(sol.begin(), sol.begin()+ k/2 - 1, sol.begin()+k);
            ans += sol[k/2 - 1];
            ans/=2;
        }
        cout << ans << endl;
    }
}
