#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int s; cin >> s;
    while (s--) {
        int n, m; 
        cin >> n >> m;
        
        int present[10] = {0};
        queue<pair<int, int>> Queue;
        int priority;
        
        for (int i = 0; i < n; i++) {
            cin >> priority;
            Queue.push(make_pair(priority, i));
            present[priority]++;
        }
        
        int Time = 0;
        int index;
        while (true) {
            priority = Queue.front().first; 
            index = Queue.front().second;
            Queue.pop();
            
            int highest = 1;
            for (int i = priority + 1; i < 10; i++) {
                if (present[i]) {
                    highest = 0;
                    break;
                }
            }

            if (highest) {
                Time++;
                if (index == m) break;
                present[priority]--;
            } 
            else 
                Queue.push(make_pair(priority, index));
        }
        cout << Time << endl;
    }
	return 0;
}
