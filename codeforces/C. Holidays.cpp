//http://www.codeforces.com/problemset/problem/44/C

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
#define FORC(i,j,n) for((i)=(j);(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)

using namespace std;

int n, m, a, b, c, d, i, j, h, len, x, y, xi[105],resp;
bool ok;


int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    scanf("%d %d", &n, &m);
    
    ok = true;
    
    FOR(i,m){
        scanf("%d %d", &a, &b);
        for( j = a; j <= b; j++){
            xi[j]++;
        }
    }
    for(i = 1; i <= n; i++){
        if(xi[i] != 1){
            ok = false;
            c = i;
            d = xi[i];
            break;
        }
    }
    if(ok)printf("OK");
    else printf("%d %d", c, d); 
    
    return 0;

}
