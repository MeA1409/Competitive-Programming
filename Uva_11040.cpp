#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) {
        int **blocks = new int* [5];
        for (int i = 0; i < 5; i++)
            blocks[i] = new int[i*2+1];
            
        for (int i = 0; i < 5; i++) 
            for (int j = 0; j < i*2+1; j += 2) 
                cin >> blocks[i][j];
                
        int j, cur = 1; 
        for (int k = 1; k <= 4; k++) {
            j = 0;
            for (int l = 0; l < k; l++, j += 2) {
                blocks[cur][j+1] = blocks[cur-1][j] - (blocks[cur][j] + blocks[cur][j+2]);
                blocks[cur][j+1] /= 2;
            }
            cur++;
        }
        
        int x = 0;
        
        for (int i = 0; i < 5; x++) {
            if (x&1) {
                for (int j = 0; j < 2*i; j++) {
                    if (j != 0) cout << " ";
                    cout << blocks[i][j] + blocks[i][j+1];
                }
            }
            else {
                for (int j = 0; j < 2*i+1; j++) {
                    if (j != 0) cout << " ";
                    cout << blocks[i][j];
                }
                i++;
            }
            cout << endl;
        } 
        
        delete(blocks);
    }
}
