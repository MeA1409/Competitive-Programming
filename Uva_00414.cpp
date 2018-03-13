#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    int total, min;
    string line;
    while (cin >> n, n > 0) {
        int perline;
        total = 0;
        min = 1999999999;
        for (int i = 0; i < n; i++) {
            getline(cin >> ws, line);
            perline = 0;
            for (int j = 0; j < 25; j++) 
                if (line[j] != 'X') perline++;
            if (perline < min) min = perline;
            total += perline;
        }
        total -= min*n;
        cout << total << endl;
    }
}
