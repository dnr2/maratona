//http://poj.org/problem?id=2140

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

int n, m, a, b, c, d, i, j, k, h, len, z, resp;
//char str[20];
long long num;
//int nums[10000];

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    scanf("%d",&n);
    
    for( i = 1; i <= (n/2)+1; i++){
        for( j = i; j <= (n/2)+1; j++){
            //P2INT(i,(i+j)*(j-i+1)/2);                        
            if( (i+j)*(j-i+1)/2 == n ) num++;
            if ( (i+j)*(j-i+1)/2 > n ) break;
        }
    }
    printf("%lld", num+1);           
    return 0;

}
