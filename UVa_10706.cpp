#include <iostream>
#include <string>

using namespace std;

const int N = 32000 + 1;
string theWorld = "";
long digitSofar[N];

int main() {
	ios_base::sync_with_stdio(0);
	
	long counter = 0;
    for (int i = 1; i < N; i++) {
        string util = to_string(i);
        theWorld += util; counter += util.size();
        digitSofar[i] = counter + digitSofar[i-1]; 
    }

    int t; cin >> t;
    while (t--) {
        long d; cin >> d;
        int lo = 0, 
            hi = N - 1;
        int mi;
        for (int i = 0; i < 16; i++) {
            mi = (lo + hi)/2;
            if (digitSofar[mi] < d) {
                if (digitSofar[mi+1] > d)
                    break;
                else
                    lo = mi + 1;
            }
            else hi = mi - 1;
        }
        // theWorld is zero-indexed
        cout << theWorld[d - digitSofar[mi] - 1] << endl;
    }
	return 0;
}
