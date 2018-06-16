#include <bits/stdc++.h>
using namespace std;

int coin[] = {5, 10, 20, 50, 100, 200};
int minCoin[201];
int pocket[6];

int min(int a, int b) {
    return a < b? a : b;
}

int input() {
    int _e = 0;
    for (int i = 0; i < 6; i++) {
        cin >> pocket[i];
        _e |= pocket[i];
    }
    return _e;
}

int solve(int id, int amount, vector <vector<int>> &memo) {
    if (amount <= 0) 
        return minCoin[(-amount)];
    if (id >= 6) return (int) 1e9;
    
    int &m = memo[id][amount];
    if (m != -1) return m;
    
    int Min = (int) 1e9; 
    for (int i = 0; i <= pocket[id]; i++) {
        Min = min(Min, i + solve(id + 1, amount - coin[id]*i, memo));
        if (amount - coin[id]*i < 0) break;
    }
    return m = Min;
}

int main() {
    ios_base::sync_with_stdio();
    
    memset(minCoin, 1000000, sizeof(minCoin));
    minCoin[0] = 0;
    for (int i = 5; i >= 0; i--) {
        for (int j = coin[i]; j < 201; j++)
            minCoin[j] = min(minCoin[j], 1 + minCoin[j-coin[i]]);
    }
    
    while (input() != 0) {
        double amt; cin >> amt;
        int amount = (int) (amt*100.0 + 1e-9);
        vector <vector <int>> memo(6, vector <int>(501, -1));
        cout << setw(3) << right << solve(0, amount, memo) << endl;
    }
	return 0;
}
