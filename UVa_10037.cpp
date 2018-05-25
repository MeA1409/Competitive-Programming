#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    if (n <= 0) continue;
	    
	    vector <int> sol(n);
	    for (int i = 0; i < n; i++)
	        cin >> sol[i];
	    if (n == 1) {
	        cout << sol[0] << endl;
	        cout << sol[0] << endl;
	        if (t) cout << endl;
	        continue;
	    }
	    vector <pii> forth;
	    vector <int> back;
	    sort(sol.begin(), sol.end());
	    
	    int answer = 0;
	    while (n > 3) {
          // let A, B be the smallest, C, D largest
          
          // time elapsed when AB -> A -> CD -> B
	        int t1 = sol[0] + sol[1] + sol[n-1] + sol[1];
          // time elapsed when AD -> A -> AC -> A
	        int t2 = sol[0] + sol[n-1] + sol[n-2] + sol[0];
          
	        if (t1 <= t2) {
	            answer += t1;
	            
	            forth.push_back(make_pair(sol[0], sol[1]));
	            back.push_back(sol[0]);
	            forth.push_back(make_pair(sol[n-2], sol[n-1]));
	            back.push_back(sol[1]);
	        }
	        else {
	            answer += t2;
	            
	            forth.push_back(make_pair(sol[0], sol[n-2]));
	            back.push_back(sol[0]);
	            forth.push_back(make_pair(sol[0], sol[n-1]));
	            back.push_back(sol[0]);
	        }
	        n -= 2;
	    }
	    if (n == 2) {
	        answer += sol[1];
	        forth.push_back(make_pair(sol[0], sol[1]));
	    }
	    else {
	        answer += sol[1] + sol[0] + sol[2];
	        forth.push_back(make_pair(sol[0], sol[n-2]));
	        back.push_back(sol[0]);
	        forth.push_back(make_pair(sol[0], sol[n-1]));
	    }
	    
	    cout << answer << endl;
	    for (int i = 0; i < forth.size(); i++) {
	        cout << forth[i].first << " " << forth[i].second << endl;
	        if (i < back.size()) cout << back[i] << endl;
	    }
	    if (t) cout << endl;
	}
	return 0;
}
