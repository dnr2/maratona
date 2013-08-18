//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1935

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int i, j, k, a, b, c, d, n ,m ;
long long l, s, p, q;

long long pa( long long x){
	return ((x * (x+1))/ 2);
}

// if( x < 100) return ((x / 10) * pa(x/10)) + pa(x % 10) + pa( x / 10);
// if( x < 100) return ((x / 10) * 45) + pa(x % 10) + pa( x / 10);

long long sum( long long x ){
	if( x < 0) return 0;
	if( x < 10) return pa(x) ;
	return ( x/10 * 45) + pa( x  % 10) + sum( x/10 );
}
int F(int x){
	if( x == 0) return x;
	if( x % 10) return x % 10;
	return F(x/10);
}

int main(){

	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
    
	while( cin >> p >> q && ( p >= 0)){		
		printf("%lld\n", sum(q) - sum(p - 1 ) );		
	}

	// for( i = 0; i < 10000; i++){
		// long long result = 0;
		// for( j = 0 ; j <= i; j++){
			// result += F(j);
		// }
		// cout << result << endl;
	// }
	
	return 0;
}
