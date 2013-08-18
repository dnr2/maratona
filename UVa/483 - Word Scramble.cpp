//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=424

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

int n, m, b, c, d, i, j, k, h, len, z, resp;
char a[1000000], str[1000000];


int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );

    
    while( gets(str) > 0){
        h = 0;        
        while(sscanf(str, "%s", a) > 0){            
            len = strlen(a);            
            while( len--){
               printf("%c", a[len]);
            }
            
            len = strlen(a);
            for( i = h; i < h + len; i++){
                str[i] = ' ';
            }
            h += len + 1;
            if(str[h]) printf(" ");
        }
        memset(str, 0, h + 1);
        printf("\n");
    }
    
    return 0;

}
