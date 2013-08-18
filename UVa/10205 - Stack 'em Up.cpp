//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1146

/*
Questão de simulação,
usamos um array para armazenar a posição das cartas e depois fazemos as mudanças dos shuffles
e imprimimos o deck na ordem final
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

int cards[2][53];
int shuff[110][53];

char buff[100];
int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);	
	scanf("%d", &t);	
	bool blank = false;
	while(t--){
		if(blank) puts("");
		blank = true;
		for(i = 1; i <= 52; i++){
			cards[0][i] = i;
		}
		memset(shuff, 0, sizeof(shuff));		
		scanf("%d", &n);
		for( i = 1; i <= n ; i++){
			for( j = 1 ; j <= 52; j++){
				scanf("%d", &shuff[i][j]);
			}
		}
		scanf("\n");
		b = 1;		
		while( gets(buff) && buff[0] ){
			// puts(buff);
			sscanf(buff, "%d\n", &a);
			for( i = 1; i <= 52; i++){
				cards[b][i] = cards[1-b][shuff[a][i]];
			}
			b = 1 - b;	
			//print
			// for( i = 1; i <= 52; i++){
				// printf("%d ", cards[1-b][i]);	
			// }
			// puts("\n");
		}
		//print
		for( i = 1; i <= 52; i++){
			switch((cards[1-b][i] % 13)){					
				case 10: printf("Jack of "); break;
				case 11: printf("Queen of "); break;
				case 12: printf("King of "); break;
				case 0: printf("Ace of "); break;
				default: printf("%d of ", (cards[1-b][i] % 13) + 1); break;					
			}
			switch( (cards[1-b][i] -1 )/ 13){					
				case 0: printf("Clubs"); break;
				case 1: printf("Diamonds"); break;
				case 2: printf("Hearts"); break;
				case 3: printf("Spades"); break;
			}	
            // printf(" -> %d", cards[1-b][i]);
            puts("");
		}
		
	}
	
	return 0;
}
