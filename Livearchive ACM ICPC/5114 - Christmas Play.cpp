//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=380&page=show_problem&problem=3115

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, aux, i, j, a, b, c, d, t, k, h;
long long m;
//char str[55][55];
long long ah[20009];


int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++){
			scanf("%lld", &ah[i]);
		}
		sort(&ah[0], &ah[n]);
		h = 0;
		m = 1000000001;
		for(i = k-1; i < n; i++){
			if( m > ah[i] - ah[h]) m = ah[i] - ah[h];
			h++;
		}
		printf("%lld\n", m );
	}
	
	return 0;
}
