#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

bool isQueue(vector <int> a, vector <int> b) {
    queue<int> util;
    int num, n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) util.push(b[i]);
        else {
            if (util.empty()) return false;
            num = util.front();
            if (num != b[i]) return false;
            util.pop();
        }
    }
    return true;
}

bool isStack(vector <int> a, vector <int> b) {
    stack <int> util;
    int num, n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) util.push(b[i]);
        else {
            if (util.empty()) return false;
            num = util.top();
            if (num != b[i]) return false;
            util.pop();
        }
    }
    return true;
}

bool isHeap(vector <int> a, vector <int> b) {
    priority_queue <int> util;
    int num, n  = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) util.push(b[i]);
        else {
            if (util.empty()) return false;
            num = util.top();
            if (num != b[i]) return false;
            util.pop();
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
	while (cin >> n) {
        vector <int> a(n),  b(n);
	    int query, num;
	    for (int i = 0; i < n; i++) 
	        cin >> a[i] >> b[i];
	    
	    bool iS = isStack(a, b),
	        iQ = isQueue(a, b),
	        iH = isHeap(a, b);
	        
	    if (iS) {
	        if (iH || iQ) cout << "not sure\n";
	        else cout << "stack\n";
	    }
	    else if (iQ) {
	        if (iH) cout << "not sure\n";
	        else cout << "queue\n";
	    }
	    else if (iH) {
	        cout << "priority queue\n";
	    }
	    else cout << "impossible\n";
	}
	return 0;
}
