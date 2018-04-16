#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector <int> vi;

int fromNet(vi &Net, int a) {
    int &Z = Net[a];
    if (Z != a)
        Z = fromNet(Net, Z);
    return Z;
}

void Union(vi &Net, vi &NetSize, int a, int b) {
    int pa = fromNet(Net, a);
    int pb = fromNet(Net, b);
    
    if (pa == pb) {
            cout << NetSize[pa] << endl;
            return;
    }
    
    if (NetSize[pa] > NetSize[pb]) {
        NetSize[pa] += NetSize[pb];
        Net[pb] = pa;
        cout << NetSize[pa] << endl;
    }
    else {
        NetSize[pb] += NetSize[pa];
        Net[pa] = pb;
        cout << NetSize[pb] << endl;
    }
} 

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    vi theSocialNet;
	    vi NetSize;
	    map <string, int> Index;
	    int n; cin >> n;
	    int i = 0;
	    
	    int indexA, indexB;
	    string nameA, nameB;
	    for (int k = 0; k < n; k++) {
	        cin >> nameA >> nameB;
	        if (!Index[nameA]) {
	            theSocialNet.push_back(i);
	            NetSize.push_back(1);
	            Index[nameA] = i+1; i++;
	        }
	        if (!Index[nameB]) {
	            theSocialNet.push_back(i);
	            NetSize.push_back(1);
	            Index[nameB] = i+1; i++;
	        }
	        indexA = Index[nameA] - 1,
	        indexB = Index[nameB] - 1;
	        Union(theSocialNet, NetSize, indexA, indexB);
	    }
	}
	return 0;
}
