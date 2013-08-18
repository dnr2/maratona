//http://acm.timus.ru/problem.aspx?space=1&num=1209

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

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
        
    
    cin >> n;
    z = n-1;
    while(n--){
        scanf("%lld", &a);
        a--;
        b = (int) (sqrt( (double)( 1 + 8*a) ) - 1)/2;        
        
        if( b* b + b -(2*a) == 0){
            if( n != z){
                printf(" 1");
            } else {
                printf("1");            
            }
        } else {            
            if( n != z){
                printf(" 0");
            } else {
                printf("0");            
            }
        }
    }

    return 0;

}
