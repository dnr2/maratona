//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2010
//#tag math matematica
//#tag combinatoria combinatories
//explicação: ver todas as possibilidades de pegar 3 pontos do grid e subtrair todos os triângulos 
//formados pelos pontos colineares


#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long i,j,k,a,b,c,d, n,m;
int caso =1;

int gdc(long long x, long long y){
	long long aux;
	while( y > 0){
		aux = x % y;
		x = y;
		y = aux;
	}
	return x;
}

int main(){
	
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	
	while(scanf("%lld %lld", &n, &m) > 0 && ( n || m)){		
		n++; m++;
		long long aux = n * m, sub;
		long long total = aux * ( aux - 1) * ( aux - 2) / 6;		
		// cout << total << endl;
		total -=  m * (n * (n-1) * (n-2) / 6) + n * (m * (m-1) * (m-2) / 6);
		// cout << total << endl;
		for( i=1; i < n; i+=1){
			for( j= 1; j < m; j+=1){
				if( gdc( i , j) == 1){
					for( k=2;;k++){
						if( i * k < n && j * k < m){
							total -=  2 * (k -1) * (n - (i * k)) * ( m- (j*k) );
						} else {
							break;
						}
					}
				}
			}
		}
		printf("Case %d: %lld\n", caso++, total);
	}
	
	return 0;
}