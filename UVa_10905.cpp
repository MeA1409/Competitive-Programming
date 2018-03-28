#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b) {
    return (a + b) > (b + a);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n, n > 0) {
        vector <string> sol(n);
        for (int i = 0; i < n; i++)
            cin >> sol[i];
        sort(sol.begin(), sol.end(), cmp);
        for (int i = 0; i < n; i++)
            cout << sol[i];
        cout << endl;
    }
}
