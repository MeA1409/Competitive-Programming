#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string v;
	int cnt = 0;
	while (getline(cin >> ws, v)) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == '\"') {
				cnt++;
				cout << (cnt & 1 ? "``" : "\'\'");
			}
			else cout << v[i];
		}
		cout << endl;
	}
}
