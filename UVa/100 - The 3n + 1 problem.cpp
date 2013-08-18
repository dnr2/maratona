//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=36

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

int n, m, b, c, d, i, j, h, len, x, y, vb, vs;
int xi[1000005];

int main(){
    freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );
    
    long long a;
    
    for(i = 1 ; i < 1000000; i++){
        a = i;
        b= 1;
        while( a != 1 ){
            if( a < i ) {                
                b += xi[a] - 1;
                break;
            }
            if( a%2 == 1) a = 3*a +1; 
            else a = a/2;
            b++;
        }
        xi[i] = (int) b;
    }
    bool change;
    while (scanf("%d %d", &i, &j) > 0){
        change = false;
        if( i > j) {
            m = i;
            i = j;
            j = m;
            change = true;
        }
        m = 0;        
        for( int cont = i; cont <= j; cont++){
            if( xi[cont] > m )m = xi[cont];
        }
        if( !change )printf("%d %d %d\n", i, j, m );
        else printf("%d %d %d\n", j, i, m );

    }

    return 0;

}
