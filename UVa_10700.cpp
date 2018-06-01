#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
	    string expr; cin >> expr;
	    
	    int num = 0;
	    
	    vector <long> Max;
	    vector <long> Min;
	    
	    char op = '+';
	    for (int i = 0; i <= expr.size(); i++) {
	        if (i < expr.size() && expr[i] <= '9' && expr[i] >= '0') 
	            num = num*10 + (expr[i] - '0');
	        else {
	            if (op == '+') {
	                if (Max.empty()) 
	                    Max.push_back(num);
	                else 
	                    Max[Max.size() - 1] += num;
	                Min.push_back(num);
	            }
	            else {
	                if (Min.empty()) 
	                    Min.push_back(num);
	                else 
	                    Min[Min.size() - 1] *= num;
	                Max.push_back(num);
	            }
	            if (i == expr.size()) break;
	            op = expr[i]; num = 0;
	        }
	    }
	    long ma = 1, mi = 0;
	    for (int i = 0; i < Max.size(); i++)
	        ma *= Max[i];
	    for (int i = 0; i < Min.size(); i++)
	        mi += Min[i];
	    cout << "The maximum and minimum are " << ma << " and " << mi << "." << endl;
	}
	return 0;
}
