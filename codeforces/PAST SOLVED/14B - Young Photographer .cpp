//http://www.codeforces.com/problemset/problem/14/B

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m, a, b, c, d, i, j, h, len, x;
char str[150];
int z;

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    
    scanf("%d %d\n", &n, &x );  
    c = 0;
    d =  1005;    
    
    for( i = 0; i < n; i++){
         scanf("%d %d\n", &a, &b );
         if( a < b ){  
             if( c < a) c = a;
             if( d > b) d = b;
         } else {
             if( c < b) c = b;
             if( d > a) d = a;
         }         
    }
	if( x >= c && x <= d)
		z = 0;
	else 
		z = (abs(x - c) < abs(x - d) )? abs(x - c) : abs(x - d);
    if( c <= d) printf("%d", z );
    else printf("%d", -1);
    
    return 0;

}
