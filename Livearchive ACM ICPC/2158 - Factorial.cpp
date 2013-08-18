//http://ahmed-aly.com/voc/Standings.jsp?ID=193

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
        
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        resp = 0;
        for( i = 5; i < 1220703125; i *= 5){
            resp += n / i;
        }
        printf("%d\n", resp);              
    }

    return 0;

}
