#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct S1{
    int x, y;
    S1() {}
    S1(int X, int Y) : x(X), y(Y) {}
    bool operator < (S1 &other) {
        return x < other.x;
    } 
};

struct S2{
    int x, y;
    S2() {}
    S2(int X, int Y) : x(X), y(Y) {}
    bool operator < (S2 &other) {
        return y > other.y;
    } 
};

int main() {
	ios_base::sync_with_stdio(0);
	int n; 
	while (cin >> n) {
	    int S[n], G[n];
	    for (int i = 0; i < n; i++)
	        cin >> S[i];
	    for (int j = 0; j < n; j++)
	        cin >> G[j];
	    
	    vector <S1> A;
	    vector <S2> B;
	    for (int i = 0; i < n; i++) {
	        if (S[i] <= G[i])
	            A.push_back(S1(S[i], G[i]));
	        else B.push_back(S2(S[i], G[i]));
	    }
	    sort(A.begin(), A.end());
	    sort(B.begin(), B.end());
	    for (int i = 0; i < B.size(); i++)
	        A.push_back(S1(B[i].x, B[i].y));
	    B.clear();
	    
	    int answ = A[0].x + A[n-1].y;
	    for (int i = 1; i < n; i++) {
	        if (A[i].x >= A[i-1].y)
	            answ += A[i].x;
	        else {
	            if (i != n-1)
	                A[i+1].x -= A[i-1].y - A[i].x;
	            answ += A[i-1].y;
	        }
	    }
	    cout << answ << endl;
	}
	return 0;
}
