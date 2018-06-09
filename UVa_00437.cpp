#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Block{
	int x, y, z;
	Block() {}
	Block(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	bool operator < (Block &other) {
		if (x != other.x) 
			return x < other.x;
		return y < other.y;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	int n; int s = 1;
	while (cin >> n, n > 0) {
		vector <Block> tower;
		int x, y, z;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			tower.push_back(Block(x, y, z));
			tower.push_back(Block(y, z, x));
			tower.push_back(Block(x, z, y));
			tower.push_back(Block(y, x, z));
			tower.push_back(Block(z, y, x));
			tower.push_back(Block(z, x, y));
		}
		
		int res = 0;
		sort(tower.begin(), tower.end());
		vector <int> height(tower.size(), 0);
		for (int i = 0; i < tower.size(); i++) {
			int util = 0;
			for (int j = 0; j < i; j++) {
				if (tower[i].x > tower[j].x && tower[i].y > tower[j].y || 
					tower[i].y > tower[j].x && tower[i].x > tower[j].y) {
						if (height[j] > util) 
							util = height[j];	
					} 
			}
			height[i] = util + tower[i].z;
			if (height[i] > res)
				res = height[i];
		}
		cout << "Case " << s++ << ": maximum height = " << res << endl;
	}
	return 0;
}
