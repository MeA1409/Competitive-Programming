#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    int s, a, f;
    while (t--) {
        cin >> s >> a >> f;
        vector <int> streets(f), avenues(f);
        for (int i = 0; i < f; i++) 
            cin >> streets[i] >> avenues[i];
        sort(streets.begin(), streets.end());
        sort(avenues.begin(), avenues.end());
        int n = f/2;
        if (f%2==0) n--;
        cout << "(Street: " << streets[n] << ", Avenue: " << avenues[n] << ")\n";
    }
}
