//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1071

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>


using namespace std;

int in[2][1010];
int mw[110];
int pd[1010][110];
int i, j, k;
int a, b, c, d, n , m, L;
int g, t;

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	cin >> t;
	while( t--){
		scanf("%d", &n);
		
        memset(pd, 0, sizeof(pd));
		
		for( i = 0 ; i < n; i++){
			scanf("%d %d", &in[0][i], &in[1][i] );
		}
		scanf("%d", &g);
		for( i = 0 ; i < g; i++){
			scanf("%d", &mw[i]);
		}
		
		// 0-1 knapsack
		for( i = in[1][0] ; i <= 100; i++){
			pd[0][i] = in[0][0];
		}
		
		for( i = 1; i < n; i++){
            for( j = 0; j < in[1][i]; j++){
               pd[i][j] = pd[i-1][j];
            }
			for( j = in[1][i]; j <= 100; j++){
				pd[i][j] = max( pd[i-1][j], pd[i-1][j - in[1][i]] + in[0][i]);
			}
		}
		
		// for( i = -1; i < n; i++){
			// for( j = 0; j <= 100; j++){
				// printf("%d\t", (i < 0)? j : pd[i][j]);
			// }
			// printf("\n");
			// if( i < 0) printf("\n");
		// }
		// printf("\n");
		
		int resp = 0;
		for( i = 0 ; i < g; i++){
			resp += pd[n-1][mw[i]];
		}
		printf("%d\n", resp);
		
	}

	return 0;
}
