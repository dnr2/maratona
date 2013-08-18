//http://br.spoj.pl/problems/MINHOCA/


#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>


//#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
//#define FOR(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));

using namespace std;

int n, m, a[105][105], b, c, d, i, j, k, h, len, x[105] , y[105], z, resp;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );

    scanf("%d %d", &n, &m);
    for( i = 0; i < n; i++){
        for( j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    
    for( i = 0; i < n; i++){
        for( j = 0; j < m; j++){
            x[i] += a[i][j];
        }
        //PINT(x[i]);
    }
    for( i = 0; i < m; i++){
        for( j = 0; j < n; j++){
            y[i] += a[j][i];
        }
        //PINT(y[i]);
    }
    h = 0;
    for( j = 0; j < n; j++){
        if( h < x[j]) h = x[j];
    }
    for( j = 0; j < m; j++){        
        if( h < y[j]) h = y[j];
    }    
    PINT(h);                   
        
    
    return 0;

}


