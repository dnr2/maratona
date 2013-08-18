//http://poj.org/problem?id=2386

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, c, d, i, j, k, h, len, z, t, u, f;   
long long num;
char str[110][110];
int pool[110][110];

int lake;

void paint(int y, int x){
    pool[y][x] = len;
    for( int a = y-1; a <= y+1; a++){
        for( int b = x-1; b <= x+1; b++){
            if( a >= 0 && b >= 0 && a < n && b < m){
				if( pool [a][b] == 0 && !(a  == y && b == x) && str[a][b] == 'W'){
					paint( a, b);
				}
            }
        }
    }
}

int main(){
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );

    scanf("%d %d", &n, &m);
    for( i = 0 ; i < n; i++){
        scanf("%s", str[i]);        
    }
    len = 0;
    for( i = 0 ; i <= n; i++){
        for( j = 0 ; j <= m ; j++){
            if(str[i][j] == 'W'){
                if( pool[i][j] == 0){
					len++;
                    paint( i, j);  
					
					// for( int cont = 0 ; cont < n; cont++){
						// for( int bla = 0 ; bla < m ; bla++){
							// printf("%d ", pool[cont][bla]);
						// }
						// printf("\n");
					// }
					// printf("\n");
					// printf("\n");
                }                                
            }
        }
    }
    
    printf("%d", len);
    return 0;

}
