//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1853

/*
Questão de programação dinâmica
teremos uma tabela bidimencionald em relação ao tamanho da string e a soma total
para preencher a tabela levamos en conta que: dado que podemos fazer uma string com
o tamanho n e soma m então podemos colocar mais uma letra de número l e formar uma nova string
de tamanho n + 1 e soma m + l
começamos considerando cada letra em ordem crescente
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, k, a, b, c, d, n ,m, w, h, t;
int l, s;
int pd[30][355];

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);	
	
	for( i = 1; i <= 26; i++){
		for( j = i-1; j > 0 ; j--){
			for( k = 355; k > 0; k--){
				if( pd[j][k] ){
					pd[j+1][k+i] += pd[j][k];
				}
			}
		}
		pd[1][i] = 1;
	}
	// for( i = 1; i <= 26; i++){
		// for( j = 1; j < 355 ; j++){
			// printf("\t%d", pd[i][j]);
		// }
		// puts("");
	// }
	c = 1;
	while(scanf("%d%d", &l, &s) == 2 && l != 0){
		printf("Case %d: ", c++); 
		if( l < 30 && s < 355){
			printf("%d\n", pd[l][s]);
		} else {
			printf("0\n");
		}
	}
	
	return 0;
}
