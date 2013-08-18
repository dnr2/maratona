#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Block {
	int x, y, z, all[3];
	Block(){}
	Block(int X, int Y, int Z) : x(X), y(Y), z(Z) { all = {x,y,z}; }
};
bool buildable(const Block& a, const Block& b) {
	return ((a.x > b.x) && (a.y > b.y)) || ((a.x > b.y) && (a.y > b.x));
}

bool operator<(const Block& a, const Block& b) {
	for (int i = 0; i < 3; i++){
		if (a.all[i] > b.all[i]) return 1;
		else if (a.all[i] < b.all[i]) return 0;
	}
	return 0;
}
int main() {
	size_t N, x, y, z, i, j, kase=0;
	while (cin>>N && N) {
		vector<Block> v(N);
		while (N-- && cin>>x>>y>>z ) {
			v.push_back(Block(x, z, y)), v.push_back(Block(x, y, z)), v.push_back(Block(y, z, x));
			v.push_back(Block(z, x, y)), v.push_back(Block(y, x, z)), v.push_back(Block(z, y, x));
		}
		sort(v.begin(), v.end());
		int maxL = 0, S[v.size()];
		for (i = 0; i < v.size(); i++) {
			S[i] = v[i].z;
			for (j = 0; j < i; j++)
				if (buildable(v[j], v[i])) S[i] = max(S[i], S[j] + v[i].z);
			maxL = max(maxL, S[i]);
		}
		printf("Case %d: maximum height = %d\n", ++kase, maxL);
	}
	return 0;
}
