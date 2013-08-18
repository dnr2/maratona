//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1130

/*
* ATENÇÂO COM O FORMATO DE I/O , uma última linha no fim botou tudo a perder!
*/

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

int n, m, b, c, d, i, j, k, h, len, x[109][109], z, resp;
char a[109][109];

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );


    int teste = 1;
    scanf("%d %d", &n, &m);
    while( n != 0 && m != 0){
        
        memset( a, 0, sizeof(a));
        memset( x, 0, sizeof(x));
        
        if(teste != 1) printf("\n");
        printf("Field #%d:\n", teste++);
        for( i = 1; i <= n; i++){        
            scanf("%s", &a[i]);
        }
        
        for( i = 1; i <= n; i++){
            for( j = 1; j <= m; j++){                
                if( a[i][j-1] == '*') {
                    x[i-1][j-1] += 1;
                    x[i-1][j] += 1;
                    x[i-1][j+1] += 1;
                    x[i][j-1] += 1;
                    x[i][j+1] += 1;
                    x[i+1][j-1] += 1;
                    x[i+1][j] += 1;
                    x[i+1][j+1] += 1;
                    
                }
                
            }
        }        
        
        for( i = 1; i <= n; i++){
            for( j = 1; j <= m; j++){                
                if( a[i][j-1] != '*') {
                    printf("%d", x[i][j]);
                } else {
                    printf("*");
                }
            }
            printf("\n");
        } 
        scanf("%d %d", &n, &m);
    }
    
    return 0;

}


