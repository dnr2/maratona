//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1716
//#tag math matemematica
//#tag quadrado mágico

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;


int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	int mat[3][3];
	int resp[3][1010];
	
	mat[0][0] = 8; mat[0][1] = 1; mat[0][2] = 6;
	mat[1][0] = 3; mat[1][1] = 5; mat[1][2] = 7; 
	mat[2][0] = 4; mat[2][1] = 9; mat[2][2] = 2;
	int  i ,j,k, N;
	while(scanf("%d", &N) > 0 && N){
		if( N&1 ){
			int sum = 3 * ( (3 * N) + 1) /2;
			int K = N/3;		
			int c = 0;			
			for( i =0;i < 3; i++){
				for( j = 0; j < K ; j++){
					resp[0][(i*K)+j] = (mat[0][i] * K) - K + j + 1;
					resp[2][(i*K)+((j*2)%K)] = (mat[2][i] * K) - j;
				}
				for( j = 0; j < K ; j++){
					resp[1][(i*K)+j] = sum - (resp[0][(i*K)+j] + resp[2][(i*K)+j]);
				}
			}
			for( i =0; i< 3;i++){
				for( j=0;j<N; j++){
					printf("%d" ,resp[i][j]);
					if( j != N-1) printf(" ");
				}
				puts("");
			}
		} else {
			puts("IMPOSSIBLE");
		}
		
	}
	
	return 0;
}