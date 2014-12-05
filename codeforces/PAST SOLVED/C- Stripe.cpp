//http://www.codeforces.com/problemset/problem/18/C

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

int n, m, a, b, c, d, i, j, h, len, x;
long long sums[100009], sum;



int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
        
    scanf("%d", &n);      
    sum = 0; 
    x = 0;   
    FOR(i,n){
         scanf("%d", &a );
         sum += a;
         sums[i] = sum;
    }    
    FOR(i,n-1){
         if(sum - sums[i] == sums[i]){
              x++;  
         }    
    }                 
    

    printf("%d", x);
    
    return 0;

}
