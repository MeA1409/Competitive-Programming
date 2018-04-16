#include <iostream>
#include <vector>

using namespace std;

int fromGroup(vector <int> &group, int a) {
    if (group[a] != a)
        group[a] = fromGroup(group, group[a]);
    return group[a];
}

bool Union(vector <int> &group, vector <int> &ranks, int a, int b) {
    int g1 = fromGroup(group, a);
    int g2 = fromGroup(group, b);
    if (g1 == g2) 
        return false;
    
    if (ranks[g1] > ranks[g2]) 
        group[g2] = g1;
    else {
        group[g1] = g2;
        if (ranks[g1] == ranks[g2])
            ranks[g2]++;
    }
    return true;
} 

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	int t = 1;
	while (cin >> n >> m, n || m) {
	    if (n < 0 || m < 0) break;
        vector <int> ranks(n);
        vector <int> group(n);
        for (int i = 0; i < n; i++)
            ranks[i] = 0, group[i] = i;
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            a--, b--;
            if (Union(group, ranks, a, b)) n--;
        }
        cout << "Case " << t++ << ": " << n << endl;
	}
	return 0;
}
