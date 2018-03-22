#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t = 1;
    int arr[3][3];
    string line;
    int dx[] = {0, 0, 1, 0, -1},
        dy[] = {0, 1, 0, -1, 0};
    while (getline(cin, line)) {
        cout << "Case #" << t++ << ":\n";

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j] = 0;
                
        int num, row, col;
        int x, y;
        for (char e : line) {
            num = e - 'a';
            if (num < 0 || num > 9) continue;
            
            row = num/3; col = num%3;
            
            for (int k = 0; k < 5; k++) {
                x = row + dx[k]; y = col + dy[k];
                if (x < 3 && y < 3 && x >= 0 && y >= 0)
                    arr[x][y] = (arr[x][y] + 1)%10;
            }
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != 0) cout << " ";
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}
