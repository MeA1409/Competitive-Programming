#include <iostream>
using namespace std;

typedef pair<int, int> pii;

const int N = 500;

int a[N][N];
int n;

int minTree[4*N][4*N];
int maxTree[4*N][4*N];

int min(int a, int b){
    return a < b? a : b;
}
int max(int a, int b) {
    return a > b? a : b;
}

void Segment(int iBranch, int lBranch, int rBranch, 
                  int iSegment, int lSegment, int rSegment) 
{
    if (lSegment == rSegment) {
        if (lBranch == rBranch) { 
            minTree[iBranch][iSegment] = a[lBranch][lSegment];
            maxTree[iBranch][iSegment] = a[lBranch][lSegment];
        }
        else {
            minTree[iBranch][iSegment] = min(minTree[iBranch*2][iSegment], 
                                        minTree[iBranch*2 + 1][iSegment]);
            maxTree[iBranch][iSegment] = max(maxTree[iBranch*2][iSegment], 
                                        maxTree[iBranch*2 + 1][iSegment]);
        }
    }
    else {
        int mSegment = (lSegment + rSegment)/2;
        Segment(iBranch, lBranch, rBranch, iSegment*2, lSegment, mSegment);
        Segment(iBranch, lBranch, rBranch, iSegment*2+1, mSegment + 1, rSegment);
        minTree[iBranch][iSegment] = min(minTree[iBranch][iSegment*2],
                                        minTree[iBranch][iSegment*2 + 1]);
        maxTree[iBranch][iSegment] = max(maxTree[iBranch][iSegment*2],
                                        maxTree[iBranch][iSegment*2 + 1]);
    }
}

void Tree(int iBranch, int lBranch, int rBranch) {
    if (lBranch != rBranch) {
        int mBranch = (lBranch + rBranch)/2;
        Tree(iBranch*2, lBranch, mBranch);
        Tree(iBranch*2+1, mBranch + 1, rBranch);
    }
    Segment(iBranch, lBranch, rBranch, 1, 0, n-1);
}

void UpdateSegment(int iBranch, int lBranch, int rBranch, int iSegment, int lSegment, int rSegment, int Col, int val) {
    if (lSegment == rSegment) {
        if (lBranch == rBranch) { 
            minTree[iBranch][iSegment] = val;
            maxTree[iBranch][iSegment] = val;
        }
        else {
            minTree[iBranch][iSegment] = min(minTree[iBranch*2][iSegment], 
                                        minTree[iBranch*2 + 1][iSegment]);
            maxTree[iBranch][iSegment] = max(maxTree[iBranch*2][iSegment], 
                                        maxTree[iBranch*2 + 1][iSegment]);
        }
    }
    else {
        int mSegment = (lSegment + rSegment)/2;
        if (Col <= mSegment)
            UpdateSegment(iBranch, lBranch, rBranch, iSegment*2, lSegment, mSegment, Col, val);
        else 
            UpdateSegment(iBranch, lBranch, rBranch, iSegment*2 + 1, mSegment + 1, rSegment, Col, val);
        minTree[iBranch][iSegment] = min(minTree[iBranch][iSegment*2],
                                        minTree[iBranch][iSegment*2 + 1]);
        maxTree[iBranch][iSegment] = max(maxTree[iBranch][iSegment*2],
                                        maxTree[iBranch][iSegment*2 + 1]);
    }
}

void Update(int iBranch, int lBranch, int rBranch, int Row, int Col, int val) {
    if (lBranch != rBranch) {
        int mBranch = (lBranch + rBranch)/2;
        if (Row <= mBranch)
            Update(iBranch*2, lBranch, mBranch, Row, Col, val);
        else 
            Update(iBranch*2+1, mBranch + 1, rBranch, Row, Col, val);
    }
    UpdateSegment(iBranch, lBranch, rBranch, 1, 0, n - 1, Col, val);
}

pii QueryCol(int iBranch, int iSegment, int lSegment, int rSegment, int colLeft, int colRight) {
    if (lSegment > colRight || rSegment < colLeft)
       return pii((1 << 30), -(1 << 30));
 
    if (colLeft <= lSegment && rSegment <= colRight)
        return pii(minTree[iBranch][iSegment], 
                    maxTree[iBranch][iSegment]);
                    
    int mSegment = (lSegment + rSegment)/2;
    pii L = QueryCol(iBranch, iSegment*2, lSegment, mSegment, colLeft, colRight);
    pii R = QueryCol(iBranch, iSegment*2 + 1, mSegment + 1, rSegment, colLeft, colRight);
    
    return pii(min(L.first, R.first), max(L.second, R.second));
}

pii Query(int iBranch, int lBranch, int rBranch, 
                  int rowUpper, int rowLower, int colLeft, int colRight)
{
    if (lBranch > rowLower || rBranch < rowUpper) 
        return pii((1 << 30), -(1 << 30));

    if (rowUpper <= lBranch && rBranch <= rowLower) 
        return QueryCol(iBranch, 1, 0, n - 1, colLeft, colRight);

    int mBranch = (lBranch + rBranch)/2;
    pii L = Query(iBranch*2, lBranch, mBranch, rowUpper, rowLower, colLeft, colRight); 
    pii R = Query(iBranch*2 + 1, mBranch+1, rBranch, rowUpper, rowLower, colLeft, colRight);
    
    return pii(min(L.first, R.first), max(L.second, R.second));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	        cin >> a[i][j];
	        
	Tree(1, 0, n-1);
	int q; cin >> q;
	
    
	while (q--) {
	    char query; cin >> query;
	    if (query == 'c') {
	        int r, c, val;
	        cin >> r >> c >> val;
	        c--, r--;
	        Update(1, 0, n - 1, r, c, val);
	    }
	    else {
	        int r1, c1, r2, c2;
	        cin >> r1 >> c1 >> r2 >> c2;
	        r1--, c1--, r2--, c2--;
	        pii answer = Query(1, 0, n-1, r1, r2, c1, c2);
	        cout << answer.second << " " << answer.first << endl;
	    }
	}
	return 0;
}
