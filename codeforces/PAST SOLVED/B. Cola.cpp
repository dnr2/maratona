//http://www.codeforces.com/contest/44/problem/B

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

int n, m, a, b, c, d, i, j, k, h, len, y[10], x[5][1000000], resp;


int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    
    scanf("%d %d %d %d", &n, &y[0], &y[1], &y[2] );
    
    n = 2*n;
    a = 1;
	for(i = 0; i <= 2; i++){        
        if(i != 0){            
            for( k = 1; k <= n; k++){
                if( x[i-1][k] != 0){
                    len = y[i];
                    h = x[i-1][k];                    
                    for(j = k + a; len > 0 && j <= n; j += a){                        
                        x[i][j] += h;
                        x[i+1][j] += h;
                        len--;
                    }            
                }    
            }                            
        }
        for(j = a; j <= a * y[i]; j += a){
            for( k = i; k <= 2; k++){
                x[k][j] += 1;
            }
        }
        a *= 2;        
	}
    printf("%d", x[2][n]);
    
    return 0;

}


