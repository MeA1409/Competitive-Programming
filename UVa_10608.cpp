#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> vi;

int max(int i, int j) {
    return (i > j)? i : j;
}

int fromGroup(vi &group, int a) {
    int &p = group[a];
    if (p != a)
        p = fromGroup(group, p);
    return p;
}

int Union(vi &group, vi &size, int a, int b) {
    int pa = fromGroup(group, a);
    int pb = fromGroup(group, b);
    if (pa == pb) return 0;
    
    if (size[pa] > size[pb]) {
        group[pb] = pa;
        size[pa] += size[pb];
        return size[pa];
    }
    else {
        group[pa] = pb;
        size[pb] += size[pa];
        return size[pb];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi group(n), size(n);
        for (int i = 0; i < n; i++)
            group[i] = i, size[i] = 1;
        
        int Max = 1;
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            a--, b--;
            Max = max(Max, Union(group, size, a, b));
        }
        cout << Max << endl;
    }
	return 0;
}
