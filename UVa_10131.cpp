#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ele;

void print(vector <int> &p, vector <int> vidx, int idx) {
	if (idx == -1) return;
	print(p, vidx, p[idx]);
	cout << vidx[idx] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	vector <ele> sol;
	int W, IQ;
	
	int idx = 1;
	while (cin >> W >> IQ) {
		sol.push_back(make_pair(make_pair(IQ, W), idx++));
	}
	
	sort(sol.rbegin(), sol.rend());
	
	vector <int> liw, ldq, vidx;
	vector <int> P, utl; 
	int j;
	idx = 0;
	
	for (int i = 0; i < sol.size(); i++) {
		pii ident = sol[i].first;
		int id = sol[i].second;
		
		int w = ident.second;
		int iq = ident.first;
		
		j = lower_bound(liw.begin(), liw.end(), w) - liw.begin();
		if (j < liw.size() && liw[j] == w) continue;
		if (j > 0 && ldq[j-1] == iq) continue;
		
		if (j == liw.size()) {
			liw.push_back(w); ldq.push_back(iq);
			utl.push_back(idx);
		}
		else {
			liw[j] = w; ldq[j] = iq;
			utl[j] = idx;
		}
		
		if (j == 0) P.push_back(-1);
		else	P.push_back(utl[j-1]);
		
		vidx.push_back(id);
		idx++;
	}
	int k = liw.size();
	cout << k << endl;
	print(P, vidx, utl[k-1]);

	return 0;
}
