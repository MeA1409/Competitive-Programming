#include <iostream>
#include <vector>
#include <map>
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
    int n, m;
    while (cin >> n >> m, n||m) {
        if (n < 0 || m < 0) break;
        
        vi group(n), size(n);
        map<string, int> idx;
        string name;
        for (int i = 0; i < n; i++) {
            cin >> name;
            idx[name] = i;
            group[i] = i, size[i] = 1;
        }
        int Max = 1;
        int idxA, idxB;
        string a, b;
        
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            idxA = idx[a]; idxB = idx[b];
            Max = max(Max, Union(group, size, idxA, idxB));
        }
        cout << Max << endl;
    }
	return 0;
}
