#include <iostream>
#include <queue>
using namespace std;

void sol(int n) {
    queue <long> nums;
    long x;
    for (int i = n+1; i <= 2*n; i++) {
        x = i*1ll*n/(i-n);
        if (x*1ll*i/(x+i) == n) 
            nums.push(i);
    }
    
    cout << nums.size() << endl;
    int temp;
    while (!nums.empty()) {
        temp = nums.front();
        cout << "1/" << n << " = 1/" 
            << temp*1ll*n/(temp-n) << " + 1/"
            << temp << endl;
        nums.pop();
    }
}

int main() {
  ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n)
	    sol(n);
	return 0;
}
