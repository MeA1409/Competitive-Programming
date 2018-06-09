#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector <int> &p, vector <int> &a, int idx) {
	if (idx == -1) return;
	print(p, a, p[idx]);
	cout << a[idx] << endl;
}

int main() {
	int max = 0;
	vector <int> li, liIdx;
	vector <int> parent, arr;
	
	int idx = 0, j;
	int x = 0;
	while (cin >> x) {
		j = upper_bound(li.begin(), li.end(), x) - li.begin();
		if (j > 0 && li[j-1] == x) continue;
		if (j == li.size()) 
			li.push_back(x),
			liIdx.push_back(idx);
		else 
			li[j] = x, 
			liIdx[j] = idx;
			
		if (j == 0) parent.push_back(-1);
		else	    parent.push_back(liIdx[j-1]);
		
		arr.push_back(x);
		idx++;
	}
	if (li.size() == 0) {
	    cout << 0 << "\n-\n";
	    return 0;
	}
	int k = li.size();
	cout << k << "\n-\n";
  print(parent, arr, liIdx[k-1]);
	return 0;
}
