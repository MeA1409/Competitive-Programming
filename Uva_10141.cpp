#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m; 
    string nameAns, name;
    double priceAns, price;
    int metsAns, mets;

    int t = 0;
    while (cin >> n >> m, n || m) {
        priceAns = 1999999999;
        metsAns = -1;
        
        for (int i = 0; i < n; i++) 
            getline(cin >> ws, name);
     
        for (int i = 0; i < m; i++) {
            getline(cin >> ws, name);
            cin >> price >> mets;
            if (mets > metsAns) {
                nameAns = name, priceAns = price;
                metsAns = mets;
            }
            else if (mets == metsAns && price < priceAns) 
                nameAns = name, priceAns = price;
            
            for (int k = 0; k < mets; k++) 
                getline(cin >> ws, name);
        }
        if (t > 0) cout << endl;
        cout << "RFP #" << ++t << endl << nameAns << endl;
    }
}
