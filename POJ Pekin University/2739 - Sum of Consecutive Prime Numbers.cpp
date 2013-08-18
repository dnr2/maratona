//http://poj.org/problem?id=2739

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

int n, m, a, b, c, d, i, j, k, len, z, resp, t;
char arr[29][29], str[29];
bool crivo[10100];
int primes[10100];

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    crivo[0] = crivo[1] = false;
    memset(crivo, true, sizeof(crivo));
    len = 0;
    FORC(i,2,10001){
        while( !crivo[i]){
            i++;
        }
        primes[len] = i;
        len++;
        for(j = 2*i; j <10053; j+= i){
            crivo[j] = false;
        }                
    }        
    scanf("%d", &n);
    int sum;    
    while(n != 0){        
        resp = 0;
        FOR(i,len){
            sum = 0;
            FORC(j,i,len){
                sum += primes[j];
                if( sum == n) resp++;
                else if( sum > n ) break;
            }            
        }
        PINT(resp);
        scanf("%d", &n);
    }    
    
    return 0;

}
