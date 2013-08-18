//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=69


#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <stack>
#include <list>

using namespace std;

int n, m, i, j, k, len, resp, t, K;
int a, b , c, d;

int main(){

    //freopen("in.txt", "r", stdin );
	//freopen("out.txt", "w", stdout );    
    
	while(scanf("%d %d %d", &n, &k, &m) > 0 && n != 0){
		
		
		bool arr[n];
		for( i = 0 ; i < n; i++){
            arr[i] = false;
        }
		len = n;
		b = 0;
		a = n-1;
		
		while( len > 0){
            c = k % len;
            d = m % len;
            
			while(c--){
                a = (a + 1) % n;
                while( arr[a] ) a = (a + 1) % n;
            }
            while(d--){
                b = (( (b - 1) % n) +n) % n ;
                while( arr[b] ) b = (( (b - 1) % n) +n) % n ;
            }
			if( b == a){
                if( a + 1 < 10) printf(" ");
				printf(" %d", a + 1);
				arr[a] = true;
				len--;
			} else {
                if( a + 1 < 10) printf(" ");
				printf(" %d", a + 1);
				if( b + 1 < 10) printf(" ");
				printf(" %d", b + 1);
				arr[a] = true;
				arr[b] = true;
				len -= 2;
			}
			if( len > 0 ) {
                printf(",") ;			
                while( arr[a] ) a = (( (a - 1) % n) +n) % n ;
                while( arr[b] ) b = (b + 1) % n;
            }
        }
		
		printf("\n"); 
		
	}
    return 0;

}
