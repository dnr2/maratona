//http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=378&page=show_problem&problem=2968

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>


using namespace std;

int in[100100][3]; 
int i, j, k;
int a, b, c, d, n , m, L;
int g, t, test;
int m1, m2, m3;

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	test = 1;
	while( scanf("%d", &n) != EOF && n != 0){
		// memset( pd, 0, sizeof(pd));
		in[0][0] = 0x7fffffff;
		scanf("%d %d %d", &a, &b, &c);
		in[0][1] = b;
		in[0][2] = b + c;
		
		for( i = 1 ; i < n; i++){
			scanf("%d %d %d", &a, &b, &c);
			m1 = min( in[i-1][0], in[i-1][1]);
			in[i][0] = m1 + a;
			m2 = min( m1, in[i-1][2]);
			in[i][1] = min( m2, in[i][0]) + b;			
			in[i][2] = min(  min( in[i-1][2], in[i-1][1] ) , in[i][1]) + c;
		}
		
		// for( j = 0 ; j < n; j++){
			// for( i = 0; i < 3; i++){
				// printf("\t%d", in[j][i]);
			// }
			// printf("\n");
		// }
		// printf("\n");
		
		printf("%d. %d\n", test++, in[n-1][1]);		
	}
	return 0;
}
