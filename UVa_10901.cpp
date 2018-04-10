  #include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define LEFT 0
#define RIGHT 1

const int INF = (int) 2e9;

int min(int a, int b) {
    return a < b? a : b;
}

int max(int a, int b) {
    return a > b? a : b;
}

int main() {
    ios_base::sync_with_stdio(0);
    int s; cin >> s;
    while (s--) {
        int n, t, m;
        cin >> n >> t >> m;
        vector <queue<pair<int, int>>> bank(2);
        vector <int> res(m);
        
        int time;
        string side;
        
        for (int i = 0; i < m; i++) {
            cin >> time >> side;
            if (side[0] == 'l') 
                bank[LEFT].push(make_pair(i, time));
            else if (side[0] == 'r')
                bank[RIGHT].push(make_pair(i, time));
        }
        
        int TIME = 0, cur = LEFT;
        int earliest, boats, idx;
        
        while (!(bank[LEFT].empty() && bank[RIGHT].empty())) {
            earliest = INF; boats = 0;
            
            if (!bank[LEFT].empty())
                earliest = bank[LEFT].front().second;
            if (!bank[RIGHT].empty()) 
                earliest = min(earliest, bank[RIGHT].front().second);
                
            TIME = max(TIME, earliest);
            while (!bank[cur].empty() 
                && bank[cur].front().second <= TIME 
                && boats < n) 
                {
                    boats++;
                    idx = bank[cur].front().first;
                    res[idx] = TIME + t;
                    bank[cur].pop();
                }
            TIME += t;
            cur ^= 1;
        }
        
        for (int i = 0; i < m; i++)
            cout << res[i] << endl;
        if (s) cout << endl;
    }
	return 0;
}
