#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000001;

int primeCheck[N];
vector <int> prime;

int main() {
	ios_base::sync_with_stdio(0);
	for (int i = 2; i < N; i++) {
	    if (!primeCheck[i]) {
	        for (int j = i*2; j < N; j += i)
	            primeCheck[j] = 1;
	        prime.push_back(i);
	    }
	}
    
    int n; int t = 1;
    while (cin >> n, n > 0) {
        long answer = 0;
        int temp, idx;
        for (int i = 0; i < prime.size(); i++) {
            temp = n - prime[i];
            idx = (upper_bound(prime.begin(), prime.end(), temp) - prime.begin()) - 1;
            if (prime[idx] <= prime[i]) break;
            answer += idx - i;
        }
        cout << "Case " << t++ << ": " << answer << endl;
    }
	return 0;
}
