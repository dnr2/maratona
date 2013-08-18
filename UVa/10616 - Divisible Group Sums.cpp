//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1557

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

long long a, b, c, d, i, j, k, l; 
int n, m, q;
long long dp[15][25];
long long in[210];

int mod( long long x, long long y){
	return ((x % y) + y) % y;
}
int set, query;
int main(){

	// freopen("out.txt", "w", stdout);
	// freopen("in.txt", "r", stdin);

	set = 1;
	while(scanf("%d %d", &n, &q ) > 0 && n != 0){
		for( i = 0 ; i < n ; i++){
			scanf("%lld", &in[i]);
		}
		printf("SET %d:\n", set++);
		query = 1;
		for( i = 0; i < q; i++){
			memset(dp, 0, sizeof(dp));
			scanf("%lld %lld", &a, &b);			
			for( j = 0 ; j < n ; j++){
				for( k = 9; k > 0; k--){
					for( l = a; l >= 0; l--){
						if(dp[k][l]){
							dp[k+1][ mod( l + in[j], a)] +=  dp[k][l];
						}
					}
				}
				dp[1][mod( in[j] , a)] += 1;
			}
			// for( j = 1 ; j <= 10; j++){
				// for( k = 0; k < a; k++){
					// printf("\t%d", dp[j][k]);
				// } 
				// puts("");
			// }			
			printf("QUERY %d: ", query++ );
			cout << dp[b][0] << endl;
		}
	}
	return 0;
}
