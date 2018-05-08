#include <iostream>
using namespace std;

int solution(int d, int n) {
    int answer = 1;
    while (d > 1) {
        answer <<= 1;
        answer |= (n&1);
        n >>= 1; d--;
    }
    return answer;
}

int main() {
	  ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int d, n; 
        cin >> d >> n;
        n--;
        int answer = solution(d, n);
        cout << answer << endl;
    }
    cin >> t;
	  return 0;
}
