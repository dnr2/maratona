//http:uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=188&page=show_problem&problem=1176

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int i, j, k, a, b, c, n, m;
bool crivo[1100000];

int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	memset(crivo, true, sizeof(crivo));
	crivo[0] = crivo[1] = false;
	
	for( i = 2; i < 1000110; i = i){	
		for( j = i + i; j <  1000110; j += i){
			crivo[j] = false;
		}
		i++;
		while(!crivo[i]) {
			i++;
		}
	}	
	
	while(scanf("%d", &n) > 0){

		c = n;
		b = 0;
		while( c > 0 ){
			b *= 10;
			b += (c % 10);
			c /= 10;			
		}
		
		if( !crivo[n]){		
			printf("%d is not prime.\n", n);
			
		} else if( crivo[n] && !crivo[b]){
			printf("%d is prime.\n" , n);
			//cout << b << endl;
		} else {			
			printf("%d is emirp.\n", n);
			//cout << b << endl;
		}
		
	}
	
	return 0;
}

