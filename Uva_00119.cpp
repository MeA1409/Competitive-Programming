#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n; int cases = 0;
	while (cin >> n) {
		string givers, takers;
		vector <string> names;
		unordered_map<string, int> net;

		for (int i = 0; i < n; i++) {
			cin >> givers, net[givers] = 0;
			names.push_back(givers);
		}
		
		int gives, revs, given;
		for (int i = 0; i < n; i++) {
			cin >> givers >> gives >> revs;

			if (revs == 0)
				continue;

			given = gives / revs;
			net[givers] -= given*revs;

			for (int j = 0; j < revs; j++) {
				cin >> takers;
				net[takers] += given;
			}
		}
		if (cases++ > 0) cout << endl;
		for (int i = 0; i < n; i++)
			cout << names[i] << " " << net[names[i]] << endl;		
	}
}
