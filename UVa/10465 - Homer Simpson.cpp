//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1406

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int i, j, k, l , t;
int n , m;
int a, b , c, d, sum, resp;

int main(){
	
	//freopen( "in.txt", "r", stdin);
	//freopen( "out.txt", "w", stdout);
	
	while(scanf("%d %d %d", &m, &n, &t) > 0){			
		
		if( n < m){
            int aux= m;
            m = n;
            n = aux;
        }
		
		int max = 0;
		a  = c = b = d = 0;
		
		for( i = 0; i * n <= t; i++){			
			c = (( t - i * n ) / m );			
			if( max < i * n + c * m){
				a = i;
				b = c;
				max = i * n + c * m;
				
			}
		}
		//printf("%d %d -> ",  b, a);
		printf("%d", a + b);
		d = t - max;
		if( d > 0 ) printf(" %d", d);		
		printf("\n");
	}
	
	return 0;
}


