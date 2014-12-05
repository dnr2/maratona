//http://www.codeforces.com/problemset/problem/9/B

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

int n, m, a, b, c, d, i, j, h, len, x, y, vb, vs;
int xi[105];
double aux;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    double min;
    scanf("%d %d %d", &n, &vb, &vs); 
    FOR(i,n){
        scanf("%d", &xi[i] );
    }    
    scanf("%d %d", &x, &y); 
    min = 10000000;
    j = 0;
    
    for(i = 1; i <n; i++){
        
        aux = (sqrt( ( ((double)(x - xi[i])) * ((double)(x - xi[i])) ) + ((double)y * (double)y)) )/ (double) vs ;
        aux += xi[i]/ (double) vb;
        if( min == aux ){
            if( abs(x - j) > abs(x - xi[i])){
                j = xi[i];
                m = i;
            }
        } else if( min > aux){
            min = aux;
            j = xi[i];
            m = i;
        }
    }
        

    printf("%d", m+1);
    
    return 0;

}
