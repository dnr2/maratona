//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1985

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)

using namespace std;

long long n, m, a, b, c, d, i, j, h, len, x, y, vb, vs;
int xi[105];
double aux;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    scanf("%lld", &n);
    
    while (n--){
        //FOR(i,n){
            scanf("%lld %lld", &a, &b);
            c = (((a-2) % 3)==0)? ((a-2)/3) : ((a-2)/3) + 1;
            d = (((b-2)%3) == 0)? ((b-2)/3) : ((b-2)/3) + 1;
            printf("%lld\n", (c * d));
        //}
    }

    return 0;

}
