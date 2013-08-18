//http://br.spoj.pl/problems/FORMULA/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <stack>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, i, j, k, len, resp, t, K;
int a, b , c, d, depth;
int g, p, s;
int corridas[110][110];
int sp[110];
int pontos[110];

int main(){
    //freopen("in.txt", "r", stdin );
	//freopen("out.txt", "w", stdout );    
    
    while( scanf("%d %d", &g, &p) > 0 && (g != 0 || p != 0)){
        
		for( i = 0 ;  i < g; i++){
			for( j = 0 ;  j < p; j++){
				scanf("%d", &corridas[i][j]);
			}		
		}
		scanf("%d", &s);
		while(s--){
			memset(pontos, 0 , sizeof(pontos));
			memset(sp, 0 , sizeof(sp));
			scanf("%d", &K);
			for( j = 0 ;  j < K; j++){
				scanf("%d", &sp[j]);		
			}
			
			for( i = 0 ;  i < g; i++){
				for( j = 0 ;  j < p; j++){
					pontos[j] += sp[corridas[i][j]-1];
				}		
			}
			int maior = 0;
			for( i = 0 ;  i < p; i++){                
				if( pontos[i] > maior) maior = pontos[i];
			}
			bool primeiro = true;
			for( i = 0 ;  i < p; i++){
				if( pontos[i] == maior) {
					if( primeiro) { 
                        printf("%d", i+1);
                        primeiro = false;
                    } 
					else printf(" %d", i+1);
				}
			}
			printf("\n");
		}

    }
    
    return 0;

}

