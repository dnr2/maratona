//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=365&page=show_problem&problem=2474

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

char str[300];

int i, j , k , n , m, resp;
int g[2][110][110];
long a, b , c, d, r, t;

void batle(){
	t = ( t == 1)? 0 : 1; 
	for( i = 1 ; i  <= r; i++){
		for( j = 1 ; j  <= c; j++){
			if( (g[t][i][j] + 1 ) % n ==  g[t][i-1][j] ){
				g[(t+1)%2][i-1][j] = g[t][i][j];
			}
			if( (g[t][i][j] + 1 ) % n ==  g[t][i][j-1]){
				g[(t+1)%2][i][j-1] = g[t][i][j];
			}
			if( (g[t][i][j] + 1 ) % n ==  g[t][i+1][j]){
				g[(t+1)%2][i+1][j] = g[t][i][j];
			}
			if( (g[t][i][j] + 1 ) % n ==  g[t][i][j+1]){
				g[(t+1)%2][i][j+1] = g[t][i][j];
			}
		}
	}
	for( i = 1 ; i  <= r; i++){
		for( j = 1 ; j  <= c; j++){
			if( g[(t+1)%2][i][j] == -1){
				g[(t+1)%2][i][j] = g[t][i][j];
			}
			g[t][i][j] = -1;
		}
	}
	if( d == k -1){ 
		for( i = 1 ; i  <= r; i++){
				printf("%d", g[(t+1)%2][i][1]);
				for( j = 2 ; j  <= c; j++){
					printf(" %d", g[(t+1)%2][i][j]);
				}
				printf("\n");
		}
	}
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d %d %d %d", &n, &r, &c, &k)> 0 && n != 0){
		memset(g, -1 , sizeof(g));
		for( i = 1 ; i  <= r; i++){
			for( j = 1 ; j  <= c; j++){
				scanf("%d", &g[0][i][j]);
			}			
		}
		t = 1;
		for( d = 0 ; d  < k; d++){
			batle();
			//printf("\n%d\n%d\n\n", k, d);
		}
		
		// for( i = 1 ; i  <= r; i++){
			// printf("%d", g[k%2][i][1]);
			// for( j = 2 ; j  <= c; j++){
				// printf(" %d", g[k%2][i][j]);
			// }
			// printf("\n");
		// }
	}
	
	return 0;
}
