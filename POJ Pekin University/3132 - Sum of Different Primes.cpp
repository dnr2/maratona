//http://poj.org/problem?id=3132

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>


#define FOR(i,n) for((i) = 0; (i) < (n); (i) ++)
#define FORC(i,j, n) for((i) = (j); (i) < (n); (i) ++)
#define PINT(i) printf("%d\n", (i));
#define P2INT(i,j) printf("%d %d\n", (i), (j));
#define SINT(i) scanf("%d", &(i));
#define S2INT(i, j) scanf("%d %d", &(i), &(j));
#define SSTR(s) scanf("%s", &(s));


using namespace std;

int n, m, c, d, i, j, k, len, z, resp, t;
long long b, a;

long long crivo[15][1320];
int primes[1320];



int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
        
    
    FORC(i,2,1320){
        crivo[0][i] = 1;
    }
    
    
    len = 0;  
    FORC(i,2,1120){
        while( !crivo[0][i] && i < 1320){
            i++;
        }
        primes[len++] = i;
        for(j = 2*i; j < 1320; j+= i){
            crivo[0][j] = 0;
        }                
    }
    
    crivo[1][2] = 1;
    
    FORC(i,1,len){
        for(j = 13; j > 0; j--){
            for(k = 1220 - primes[i]; k >= 0; k--){
                if( crivo[j][k] > 0){
                    crivo[j+1][k + primes[i]] += crivo[j][k];
                }
            }
        }
        crivo[1][primes[i]] += 1;
    }
    
    /*FORC(i,1, 15){
        FORC(j,0, 110){
            printf("%d:%lld ", j, crivo[i][j]);            
        }              
        printf("\n");
    }*/
    

    scanf("%d %d", &n, &k);
    while(n != 0 && k != 0){
        
        printf("%lld\n", crivo[k][n]);
                
        scanf("%d %d", &n, &k);
        
    }

    return 0;

}
