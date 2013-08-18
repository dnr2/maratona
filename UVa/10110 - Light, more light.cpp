//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1051

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

long long n, num, aux, a, b, i, j, k;
int coins[5] =  { 50, 25,  10, 5, 1};
//int pd[5][7490];
 
 

int main(){
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
    scanf("%lld", &n);            
    while( n !=  0){
        long long  raiz = (long long) sqrt(n);
        //printf("%lld\n", raiz); 
        if( raiz * raiz == n ){  
            printf("yes\n"); 
        } else {
            printf("no\n");  
        }
        scanf("%lld", &n);            
    }
  
    return 0;

}
